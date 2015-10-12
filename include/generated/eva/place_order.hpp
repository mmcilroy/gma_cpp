#pragma once

#include "eva/pb/PlaceOrder.pb.h"

namespace eva {

class place_order
{
friend std::ostream& operator<<( std::ostream&, const place_order& );
public:
    void user( std::string );

    std::string user() const;

    void clordid( std::string );

    std::string clordid() const;

    void symbol( std::string );

    std::string symbol() const;

    void side( std::string );

    std::string side() const;

    void ord_type( std::string );

    std::string ord_type() const;

    void quantity( uint32_t );

    uint32_t quantity() const;

    void price( uint32_t );

    uint32_t price() const;

    void appendage( uint32_t, std::string );

    std::string appendage( uint32_t ) const;

    const ::google::protobuf::Map< ::google::protobuf::uint32, ::std::string >& appendage() const;

    size_t size() const;

    void parse( const char*, size_t );

    void serialize( char*, size_t ) const;

private:
    PlaceOrder pb_;
};

#include "place_order.inl"

}

