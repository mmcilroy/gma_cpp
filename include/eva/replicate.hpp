#pragma once

#include "eva/event.hpp"

#include <boost/asio.hpp>

using boost::asio::ip::tcp;

class replicate_session;

namespace eva {

class replicate_master
{
public:
    replicate_master() :
        socket_( io_ )
    {
        boost::asio::ip::tcp::resolver resolver( io_ );
        boost::asio::ip::tcp::resolver::query query( boost::asio::ip::tcp::v4(), "localhost", "14101" );
        boost::asio::ip::tcp::resolver::iterator it = resolver.resolve( query );
        boost::asio::connect( socket_, it );
    }

    void write( const eva::event& ev )
    {
        boost::asio::write(
            socket_,
            boost::asio::buffer(
                ev.buffer(),
                ev.length() + EVENT_HEADER_SIZE ) );
    }

private:
    boost::asio::io_service io_;

    boost::asio::ip::tcp::socket socket_;
};

class replicate_session : public std::enable_shared_from_this< replicate_session >
{
public:
    replicate_session( tcp::socket socket, std::function< void( const eva::event& ) > handler ) :
        handler_( handler ),
        socket_( std::move( socket ) )
    {
    }

    ~replicate_session()
    {
    }

    void read()
    {
        auto self( shared_from_this() );

        socket_.async_read_some(
            boost::asio::buffer( ev_.buffer(), EVENT_BUFFER_SIZE ),
            [ this, self ]( boost::system::error_code ec, std::size_t length )
            {
                if( !ec && length > 0 )
                {
                    handler_( ev_ );
                    read();
                }
            } );
    }

    std::function< void( const eva::event& ) > handler_;

    tcp::socket socket_;

    eva::event ev_;
};

class replicate_slave
{
public:
    replicate_slave( std::function< void( const eva::event& ) > handler ) :
        handler_( handler ),
        acceptor_( io_, tcp::endpoint( tcp::v4(), 14101 ) ),
        socket_( io_ ),
        thr_( &replicate_slave::thr_fn, this )
    {
    }

    void join()
    {
        thr_.join();
    }

private:
    void do_accept()
    {
        acceptor_.async_accept(
            socket_,
            [ & ]( boost::system::error_code ec )
            {
                if ( !ec ) {
                    std::make_shared< replicate_session >( std::move( socket_ ), handler_ )->read();
                }

                do_accept();
            } );
    }

    void thr_fn()
    {
        do_accept();
        io_.run();
    }

    std::function< void( const eva::event& ) > handler_;

    boost::asio::io_service io_;

    tcp::acceptor acceptor_;

    tcp::socket socket_;

    std::thread thr_;
};

}
