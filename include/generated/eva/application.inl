inline application::application() :
    journal_( "journal.bin", false ),
    pub_( 8 ),
    jnl_sub_( pub_.subscribe() ),
    rep_sub_( jnl_sub_.subscribe() ),
    biz_sub_( rep_sub_.subscribe() ),
    jnl_thr_( &application::jnl_thr_fn, this ),
    rep_thr_( &application::rep_thr_fn, this ),
    biz_thr_( &application::biz_thr_fn, this )
{
}

inline void application::recover()
{
    journal_.recover( [ & ]( const eva::event& ev  )
    {
        event_type type = ev.type();
        if( type == event_type::PLACE_ORDER )
        {
            ev.parse< place_order >( [ & ]( const place_order& msg ) {
                process( msg, true );
            } );
        }
        else
        if( type == event_type::ORDER_EXECUTED )
        {
            ev.parse< order_executed >( [ & ]( const order_executed& msg ) {
                process( msg, true );
            } );
        }
        else
        if( type == event_type::UPDATE_CACHE )
        {
            ev.parse< update_cache >( [ & ]( const update_cache& msg ) {
                process( msg, true );
            } );
        }
    } );
}

inline void application::inject( const place_order& msg )
{
    pub_.publish( 1, [ & ]( event& ev, size_t n ) {
        ev.serialize( msg );
    } );
}

inline void application::inject( const order_executed& msg )
{
    pub_.publish( 1, [ & ]( event& ev, size_t n ) {
        ev.serialize( msg );
    } );
}

inline void application::inject( const update_cache& msg )
{
    pub_.publish( 1, [ & ]( event& ev, size_t n ) {
        ev.serialize( msg );
    } );
}

inline void application::join()
{
    biz_thr_.join();
}

inline void application::jnl_thr_fn()
{
    jnl_sub_.dispatch( [&]( const event& ev, size_t rem )
    {
        journal_.write( ev );
        journal_.flush();
        return false;
    } );
}

inline void application::rep_thr_fn()
{
    rep_sub_.dispatch( [&]( const event& ev, size_t rem )
    {
        replicate_.write( ev );
        return false;
    } );
}

inline void application::biz_thr_fn()
{
    biz_sub_.dispatch( [&]( const event& ev, size_t rem )
    {
        event_type type = ev.type();

        if( type == event_type::PLACE_ORDER )
        {
            ev.parse< place_order >( [ & ]( const place_order& msg ) {
                process( msg, false );
            } );
        }
        else
        if( type == event_type::ORDER_EXECUTED )
        {
            ev.parse< order_executed >( [ & ]( const order_executed& msg ) {
                process( msg, false );
            } );
        }
        else
        if( type == event_type::UPDATE_CACHE )
        {
            ev.parse< update_cache >( [ & ]( const update_cache& msg ) {
                process( msg, false );
            } );
        }

        return false;
    } );
}

