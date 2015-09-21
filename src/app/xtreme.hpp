#pragma once

#include "eva/place_order.hpp"
#include "eva/order_executed.hpp"
#include "config.hpp"

#include <boost/uuid/uuid.hpp>
#include <boost/uuid/uuid_generators.hpp>
#include <boost/uuid/uuid_io.hpp>

namespace xt {

class session
{
public:
    session( std::function< void( const eva::order_executed& ) > );

    virtual std::string id();

    virtual void submit( const eva::place_order& );

private:
    void process( fix::session&, const fix::message& );

    void fix_thr_fn();

    std::function< void( const eva::order_executed& ) > handler_;

    fix::session_factory factory_;
    fix::session* session_;
    fix::tcp fix_;

    std::thread fix_thr_;
};



session::session( std::function< void( const eva::order_executed& ) > handler ) :
    handler_( handler ),
    fix_( factory_, [ & ]( fix::session& sess, const fix::message& msg ) {
        process( sess, msg );
    } ),
    fix_thr_( &session::fix_thr_fn, this )
{
}

void session::process( fix::session& sess, const fix::message& msg )
{
    fix::field_map fmap = msg.map();

    eva::order_executed oe;
    oe.clordid( fmap[ 11 ] );
    oe.symbol( fmap[ 55 ] );
    oe.side( fmap[ 54 ] );
    oe.ord_type( fmap[ 40 ] );
    oe.quantity( boost::lexical_cast< int >( fmap[ 38 ] ) );
    oe.price( boost::lexical_cast< int >( fmap[ 44 ] ) );
    oe.ord_status( fmap[ 39 ] );
    oe.exec_type( fmap[ 150 ] );
    oe.last_price( boost::lexical_cast< int >( fmap[ 31 ] ) );
    oe.last_qty( boost::lexical_cast< int >( fmap[ 32 ] ) );

    handler_( oe );
}

std::string session::id()
{
    static boost::uuids::random_generator generator;
    boost::uuids::uuid u = generator();
    return to_string( u );
}

void session::submit( const eva::place_order& po )
{
    fix::message body;
    body.add( 11, po.clordid() );
    body.add( 55, po.symbol() );
    body.add( 54, po.side() );
    body.add( 40, po.ord_type() );
    body.add( 38, po.quantity() );
    body.add( 44, po.price() );
 
    for( auto it = po.appendage().begin(); it != po.appendage().end(); it++ ) {
        body.add( it->first, it->second );
    }

    session_->send( "D", body );
}

void session::fix_thr_fn()
{
    session_ = fix_.connect( FIX_CONNECTOR_ADDRESS, fix::user( "FIX.4.4", "XT", "VENUE" ) );
    fix_.start();
}

}
