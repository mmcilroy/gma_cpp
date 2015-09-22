inline std::ostream& operator<<( std::ostream& out, const place_order& msg )
{
    out << msg.pb_.DebugString();
    return out;
}

inline void place_order::user( std::string v )
{
    pb_.set_user( v );
}

inline std::string place_order::user() const
{
    return pb_.user();
}

inline void place_order::clordid( std::string v )
{
    pb_.set_clordid( v );
}

inline std::string place_order::clordid() const
{
    return pb_.clordid();
}

inline void place_order::symbol( std::string v )
{
    pb_.set_symbol( v );
}

inline std::string place_order::symbol() const
{
    return pb_.symbol();
}

inline void place_order::side( std::string v )
{
    pb_.set_side( v );
}

inline std::string place_order::side() const
{
    return pb_.side();
}

inline void place_order::ord_type( std::string v )
{
    pb_.set_ord_type( v );
}

inline std::string place_order::ord_type() const
{
    return pb_.ord_type();
}

inline void place_order::quantity( uint32_t v )
{
    pb_.set_quantity( v );
}

inline uint32_t place_order::quantity() const
{
    return pb_.quantity();
}

inline void place_order::price( uint32_t v )
{
    pb_.set_price( v );
}

inline uint32_t place_order::price() const
{
    return pb_.price();
}

inline void place_order::appendage( uint32_t k, std::string v )
{
    (*pb_.mutable_appendage())[ k ] = v;
}

inline std::string place_order::appendage( uint32_t k ) const
{
    return pb_.appendage().at( k );
}

inline const ::google::protobuf::Map< ::google::protobuf::uint32, ::std::string >& place_order::appendage() const
{
    return pb_.appendage();
}

inline size_t place_order::size() const
{
    return pb_.ByteSize();
}

inline void place_order::parse( const char* buf, size_t len )
{
    pb_.ParseFromArray( buf, len );
}

inline void place_order::serialize( char* buf, size_t len ) const
{
    pb_.SerializeToArray( buf, len );
}

