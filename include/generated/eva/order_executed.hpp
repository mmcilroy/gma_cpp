#pragma once

#include "eva/pb/OrderExecuted.pb.h"

namespace eva {

class order_executed
{
friend std::ostream& operator<<( std::ostream&, const order_executed& );
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

    void ord_status( std::string );

    std::string ord_status() const;

    void exec_type( std::string );

    std::string exec_type() const;

    void last_qty( uint32_t );

    uint32_t last_qty() const;

    void last_price( uint32_t );

    uint32_t last_price() const;

    void appendage( uint32_t, std::string );

    std::string appendage( uint32_t ) const;

    const ::google::protobuf::Map< ::google::protobuf::uint32, ::std::string >& appendage() const;

    size_t size() const;

    void parse( const std::string& );

    void serialize( std::string& ) const;

    void parse( const char*, size_t );

    void serialize( char*, size_t ) const;

private:
    OrderExecuted pb_;
};

#include "order_executed.inl"

}

