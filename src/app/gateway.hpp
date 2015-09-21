#pragma once

#include "eva/application.hpp"
#include "fix/tcp.hpp"

#include "config.hpp"
#include "translate.hpp"
#include "xtreme.hpp"


class gma_gateway : public eva::application
{
public:
    gma_gateway();

protected:
    void process( fix::session&, const fix::message& );

    void process( const eva::place_order&, bool ) override;

    void process( const eva::order_executed&, bool ) override;

    std::string cache_get( const std::string& ) const;

    void cache_set( const std::string&, const std::string& );

    template< typename T >
    void inject( const fix::field_map& );

private:
    void fix_thr_fn();

    xt::session xt_;

    fix::session_factory factory_;
    fix::tcp fix_;

    std::thread fix_thr_;

    std::map< std::string, std::string > cache_;
};



gma_gateway::gma_gateway() :
    xt_( [ & ]( const eva::order_executed& oe ) {
        eva::application::inject( oe );
    } ),
    fix_( factory_, [ & ]( fix::session& sess, const fix::message& msg ) {
        process( sess, msg );
    } ),
    fix_thr_( &gma_gateway::fix_thr_fn, this )
{
}

void gma_gateway::process( fix::session& sess, const fix::message& msg )
{
    fix::field_map fmap = msg.map();
    if( fmap[ 35 ] == "D" ) {
        inject< eva::place_order >( fmap );
    }
}

void gma_gateway::process( const eva::place_order& po, bool recovery )
{
    std::cout << std::endl << "event place_order:" << std::endl << po;

    // get the upstream and upstream ids
    std::string ds_id = xt_.id();
    std::string us_id = po.clordid();

    // store a mapping between them
    cache_set( "id.us." + ds_id, us_id );
    cache_set( "id.ds." + us_id, ds_id );

    // remember the session we received the fix message from
    cache_set( "reply." + ds_id, po.user() );

    // replace upstream clordid with xt generated one
    ((eva::place_order&)po).clordid( ds_id );

    if( !recovery ) {
        xt_.submit( po );
    }
}

void gma_gateway::process( const eva::order_executed& oe, bool recovery )
{
    std::cout << std::endl << "event order_executed:" << std::endl << oe;

    // get the upstream and downstream ids
    std::string ds_id = oe.clordid();
    std::string us_id = cache_get( "id.us." + ds_id );

    // replace the downstream id with the upstream id
    ((eva::order_executed&)oe).clordid( us_id );

    // translate event to upstream message format
    fix::field_map fmap;
    translate( oe, fmap );

    // check what user message should be sent to
    std::string user = cache_get( "reply." + ds_id );

    // send message back upstream
    if( !recovery )
    {
        fix::session* sess = factory_.get_session( user );
        if( sess )
        {
            fix::message body;
            body.map( fmap );
            sess->send( "8", body );
        }
    }
}

std::string gma_gateway::cache_get( const std::string& k ) const
{
    std::string v = cache_.at( k );
    std::cout << "cache_get: " << k << " = " << v << std::endl;
    return v;
}

void gma_gateway::cache_set( const std::string& k, const std::string& v )
{
    std::cout << "cache_set: " << k << " = " << v << std::endl;
    cache_[ k ] = v;
}

template< typename T >
void gma_gateway::inject( const fix::field_map& fmap )
{
    T ev;
    translate( fmap, ev );
    eva::application::inject( ev );
}

void gma_gateway::fix_thr_fn()
{
    fix_.accept( FIX_ACCEPTOR_ADDRESS );
    fix_.start();
}
