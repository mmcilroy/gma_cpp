#pragma once

#include "eva/event.hpp"
#include <boost/asio.hpp>

using boost::asio::ip::tcp;

class replicate_session;

namespace eva {

class replicate_session : public std::enable_shared_from_this< replicate_session >
{
public:
    replicate_session( tcp::socket socket, std::function< void( const eva::event& ) > handler );

    void read();

    std::function< void( const eva::event& ) > handler_;

    tcp::socket socket_;

    eva::event ev_;
};



class replicate_master
{
public:
    replicate_master();

    void write( const eva::event& ev );

private:
    boost::asio::io_service io_;

    boost::asio::ip::tcp::socket socket_;
};



class replicate_slave
{
public:
    replicate_slave( std::function< void( const eva::event& ) > handler );

    void join();

private:
    void do_accept();

    void thr_fn();

    std::function< void( const eva::event& ) > handler_;

    boost::asio::io_service io_;

    tcp::acceptor acceptor_;

    tcp::socket socket_;

    std::thread thr_;
};



#include "replicate.inl"

}
