#include <cstdlib>
#include <iostream>
#include <memory>
#include <utility>
#include <boost/asio.hpp>

using boost::asio::ip::tcp;

const size_t ADMIN_BUFFER_SIZE = 1024;

class session : public std::enable_shared_from_this< session >
{
public:
    session( tcp::socket socket, uint32_t id, std::function< void( uint32_t, const std::string& ) > handler ) :
        id_( id ),
        handler_( handler ),
        socket_( std::move( socket ) )
    {
    }

    ~session()
    {
    }

    void read()
    {
        auto self( shared_from_this() );

        socket_.async_read_some(
            boost::asio::buffer( buffer_, ADMIN_BUFFER_SIZE ),
            [ this, self ]( boost::system::error_code ec, std::size_t length )
            {
                if( !ec && length > 0 )
                {
                    buffer_[ length-2 ] = 0;
                    handler_( id_, std::string( buffer_ ) );
                    read();
                }
            } );
    }

    uint32_t id_;

    std::function< void( uint32_t, const std::string& ) > handler_;

    tcp::socket socket_;

    char buffer_[ ADMIN_BUFFER_SIZE ];
};

class admin_server
{
public:
    admin_server( std::function< void( uint32_t, const std::string& ) > handler ) :
        handler_( handler ),
        acceptor_( io_, tcp::endpoint( tcp::v4(), 18000 ) ),
        socket_( io_ ),
        id_( 0 ),
        thr_( &admin_server::thr_fn, this )
    {
    }

    void send( uint32_t id, std::string str )
    {
        str.append( "\r\n" );

        session* sess = sessions_[ id ];
        boost::asio::write(
            sess->socket_,
            boost::asio::buffer(
                str.c_str(),
                str.size() ) );
    }

private:
    void do_accept()
    {
        acceptor_.async_accept(
            socket_,
            [ & ]( boost::system::error_code ec )
            {
                if ( !ec )
                {
                    auto sess = std::make_shared< session >( std::move( socket_ ), id_, handler_ );
                    sessions_[ id_++ ] = sess.get();
                    sess->read();
                }

                do_accept();
            } );
    }

    void thr_fn()
    {
        do_accept();
        io_.run();
    }

    uint32_t id_;

    std::function< void( uint32_t, const std::string& ) > handler_;

    boost::asio::io_service io_;

    tcp::acceptor acceptor_;

    tcp::socket socket_;

    std::map< uint32_t, session* > sessions_;

    std::thread thr_;
};
