inline replicate_master::replicate_master() :
    socket_( io_ )
{
    boost::asio::ip::tcp::resolver resolver( io_ );
    boost::asio::ip::tcp::resolver::query query( boost::asio::ip::tcp::v4(), "localhost", "14101" );
    boost::asio::ip::tcp::resolver::iterator it = resolver.resolve( query );
    boost::asio::connect( socket_, it );
}

inline void replicate_master::write( const eva::event& ev )
{
    boost::asio::write(
        socket_,
        boost::asio::buffer(
            ev.buffer(),
            ev.length() + EVENT_HEADER_SIZE ) );
}

inline replicate_session::replicate_session( tcp::socket socket, std::function< void( const eva::event& ) > handler ) :
    handler_( handler ),
    socket_( std::move( socket ) )
{
}

inline void replicate_session::read()
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

inline replicate_slave::replicate_slave( std::function< void( const eva::event& ) > handler ) :
    handler_( handler ),
    acceptor_( io_, tcp::endpoint( tcp::v4(), 14101 ) ),
    socket_( io_ ),
    thr_( &replicate_slave::thr_fn, this )
{
}

inline void replicate_slave::join()
{
    thr_.join();
}

inline void replicate_slave::do_accept()
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

inline void replicate_slave::thr_fn()
{
    do_accept();
    io_.run();
}
