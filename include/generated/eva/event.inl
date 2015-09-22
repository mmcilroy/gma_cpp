inline std::ostream& operator<<( std::ostream& out, const event& ev )
{
    event_type type = ev.type();
        if( type == event_type::PLACE_ORDER )
        {
            ev.parse< place_order >( [ & ]( const place_order& msg ) {
                out << msg;
            } );
        }
        else
        if( type == event_type::ORDER_EXECUTED )
        {
            ev.parse< order_executed >( [ & ]( const order_executed& msg ) {
                out << msg;
            } );
        }
        else
        if( type == event_type::UPDATE_CACHE )
        {
            ev.parse< update_cache >( [ & ]( const update_cache& msg ) {
                out << msg;
            } );
        }
    return out;
}
inline char* event::buffer()
{
    return buffer_;
}

inline const char* event::buffer() const
{
    return buffer_;
}

inline event_type event::type() const
{
    header hdr;
    hdr.parse( buffer_, EVENT_HEADER_SIZE );
    return (event_type)hdr.type();
}

inline size_t event::length() const
{
    header hdr;
    hdr.parse( buffer_, EVENT_HEADER_SIZE );
    return hdr.length();
}

inline void event::parse( place_order& msg ) const
{
    parse( event_type::PLACE_ORDER, msg );
}

inline void event::serialize( const place_order& msg )
{
    serialize( event_type::PLACE_ORDER, msg );
}

inline void event::parse( order_executed& msg ) const
{
    parse( event_type::ORDER_EXECUTED, msg );
}

inline void event::serialize( const order_executed& msg )
{
    serialize( event_type::ORDER_EXECUTED, msg );
}

inline void event::parse( update_cache& msg ) const
{
    parse( event_type::UPDATE_CACHE, msg );
}

inline void event::serialize( const update_cache& msg )
{
    serialize( event_type::UPDATE_CACHE, msg );
}

template< typename T, typename F >
inline void event::parse( F handler ) const
{
    T msg;
    parse( msg );
    handler( msg );
}

template< typename T >
inline void event::parse( event_type type, T& msg ) const
{
    header hdr;
    hdr.parse( buffer_, EVENT_HEADER_SIZE );
    if( hdr.type() == type ) {
        msg.parse( buffer_ + EVENT_HEADER_SIZE, hdr.length() );
    } else {
        // error!
    }
}

template< typename T >
inline void event::serialize( event_type type, const T& msg )
{
    header hdr;
    hdr.type( type );
    hdr.length( msg.size() );
    hdr.serialize( buffer_, EVENT_HEADER_SIZE );
    msg.serialize( buffer_ + EVENT_HEADER_SIZE, msg.size() );
}

