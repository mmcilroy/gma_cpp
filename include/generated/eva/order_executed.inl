inline std::ostream& operator<<( std::ostream& out, const order_executed& msg )
{
    out << msg.pb_.DebugString();
    return out;
}

inline void order_executed::user( std::string v )
{
    pb_.set_user( v );
}

inline std::string order_executed::user() const
{
    return pb_.user();
}

inline void order_executed::clordid( std::string v )
{
    pb_.set_clordid( v );
}

inline std::string order_executed::clordid() const
{
    return pb_.clordid();
}

inline void order_executed::symbol( std::string v )
{
    pb_.set_symbol( v );
}

inline std::string order_executed::symbol() const
{
    return pb_.symbol();
}

inline void order_executed::side( std::string v )
{
    pb_.set_side( v );
}

inline std::string order_executed::side() const
{
    return pb_.side();
}

inline void order_executed::ord_type( std::string v )
{
    pb_.set_ord_type( v );
}

inline std::string order_executed::ord_type() const
{
    return pb_.ord_type();
}

inline void order_executed::quantity( uint32_t v )
{
    pb_.set_quantity( v );
}

inline uint32_t order_executed::quantity() const
{
    return pb_.quantity();
}

inline void order_executed::price( uint32_t v )
{
    pb_.set_price( v );
}

inline uint32_t order_executed::price() const
{
    return pb_.price();
}

inline void order_executed::ord_status( std::string v )
{
    pb_.set_ord_status( v );
}

inline std::string order_executed::ord_status() const
{
    return pb_.ord_status();
}

inline void order_executed::exec_type( std::string v )
{
    pb_.set_exec_type( v );
}

inline std::string order_executed::exec_type() const
{
    return pb_.exec_type();
}

inline void order_executed::last_qty( uint32_t v )
{
    pb_.set_last_qty( v );
}

inline uint32_t order_executed::last_qty() const
{
    return pb_.last_qty();
}

inline void order_executed::last_price( uint32_t v )
{
    pb_.set_last_price( v );
}

inline uint32_t order_executed::last_price() const
{
    return pb_.last_price();
}

inline void order_executed::appendage( uint32_t k, std::string v )
{
    (*pb_.mutable_appendage())[ k ] = v;
}

inline std::string order_executed::appendage( uint32_t k ) const
{
    return pb_.appendage().at( k );
}

inline const ::google::protobuf::Map< ::google::protobuf::uint32, ::std::string >& order_executed::appendage() const
{
    return pb_.appendage();
}

inline size_t order_executed::size() const
{
    return pb_.ByteSize();
}

inline void order_executed::parse( const char* buf, size_t len )
{
    pb_.ParseFromArray( buf, len );
}

inline void order_executed::serialize( char* buf, size_t len ) const
{
    pb_.SerializeToArray( buf, len );
}

