inline std::ostream& operator<<( std::ostream& out, const update_cache& msg )
{
    out << msg.pb_.DebugString();
    return out;
}

inline void update_cache::key( std::string v )
{
    pb_.set_key( v );
}

inline std::string update_cache::key() const
{
    return pb_.key();
}

inline void update_cache::value( std::string v )
{
    pb_.set_value( v );
}

inline std::string update_cache::value() const
{
    return pb_.value();
}

inline size_t update_cache::size() const
{
    return pb_.ByteSize();
}

inline void update_cache::parse( const char* buf, size_t len )
{
    pb_.ParseFromArray( buf, len );
}

inline void update_cache::serialize( char* buf, size_t len ) const
{
    pb_.SerializeToArray( buf, len );
}

