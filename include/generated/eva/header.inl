inline std::ostream& operator<<( std::ostream& out, const header& msg )
{
    out << msg.pb_.DebugString();
    return out;
}

inline void header::type( int32_t v )
{
    pb_.set_type( v );
}

inline int32_t header::type() const
{
    return pb_.type();
}

inline void header::length( int32_t v )
{
    pb_.set_length( v );
}

inline int32_t header::length() const
{
    return pb_.length();
}

inline size_t header::size() const
{
    return pb_.ByteSize();
}

inline void header::parse( const char* buf, size_t len )
{
    pb_.ParseFromArray( buf, len );
}

inline void header::serialize( char* buf, size_t len ) const
{
    pb_.SerializeToArray( buf, len );
}

