#pragma once

#include "eva/event.hpp"
#include "fix/message.hpp"

void translate( const fix::field_map& fmap, eva::place_order& po )
{
    po.user( fmap.at( 49 ) );
    po.clordid( fmap.at( 11 ) );
    po.symbol( fmap.at( 55 ) );
    po.side( fmap.at( 54 ) );
    po.ord_type( fmap.at( 40 ) );
    po.quantity( boost::lexical_cast< int >( fmap.at( 38 ) ) );
    po.price( boost::lexical_cast< int >( fmap.at( 44 ) ) );
    po.appendage( 58, "hi1" );
}

void translate( const eva::order_executed& oe, fix::field_map& fmap )
{
    fmap[ 11 ] = oe.clordid();
    fmap[ 55 ] = oe.symbol();
    fmap[ 54 ] = oe.side();
    fmap[ 40 ] = oe.ord_type();
    fmap[ 39 ] = oe.ord_status();
    fmap[ 150 ] = oe.exec_type();
    fmap[ 38 ] = boost::lexical_cast< std::string >( oe.quantity() );
    fmap[ 44 ] = boost::lexical_cast< std::string >( oe.price() );
    fmap[ 31 ] = boost::lexical_cast< std::string >( oe.last_price() );
    fmap[ 32 ] = boost::lexical_cast< std::string >( oe.last_qty() );
}
