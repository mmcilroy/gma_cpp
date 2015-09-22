#pragma once

#include "eva/application.hpp"
#include "fix/tcp.hpp"

#include "admin.hpp"
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

    void process( const eva::update_cache&, bool ) override;

    void process_admin( uint32_t, const std::string& );

    std::string cache_get( const std::string& ) const;

    void cache_set( const std::string&, const std::string& );

    template< typename T >
    void inject( const fix::field_map& );

private:
    void fix_thr_fn();

    admin_server admin_;

    xt::session xt_;

    fix::session_factory factory_;
    fix::tcp fix_;

    std::thread fix_thr_;

    std::map< std::string, std::string > cache_;
};



gma_gateway::gma_gateway() :
    admin_( [ & ]( uint32_t id, const std::string& str ) {
        process_admin( id, str );
    } ),
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

    if( !recovery )
    {
        // replace upstream clordid with xt generated one
        ((eva::place_order&)po).clordid( ds_id );
        xt_.submit( po );
    }
}

void gma_gateway::process( const eva::order_executed& oe, bool recovery )
{
    std::cout << std::endl << "event order_executed:" << std::endl << oe;

    if( !recovery )
    {
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
        fix::session* sess = factory_.get_session( user );
        if( sess )
        {
            fix::message body;
            body.map( fmap );
            sess->send( "8", body );
        }
    }
}

void gma_gateway::process( const eva::update_cache& uc, bool recovery )
{
    std::cout << std::endl << "event update_cache:" << std::endl << uc;

    cache_set( uc.key(), uc.value() );
}

void gma_gateway::process_admin( uint32_t id, const std::string& cmd )
{
    std::vector< std::string > parts;
    boost::split( parts, cmd, boost::is_any_of( " " ) );

    if( parts[ 0 ] == "update" && parts.size() == 3 )
    {
        eva::update_cache uc;
        uc.key( parts[ 1 ] );
        uc.value( parts[ 2 ] );
        eva::application::inject( uc );
        admin_.send( id, "OK" );
    }
    else
    if( parts[ 0 ] == "query" && parts.size() == 2 )
    {
        admin_.send( id, cache_get( parts[ 1 ] ) );
    }
    else
    {
        admin_.send( id, "ERR" );
    }
}

std::string gma_gateway::cache_get( const std::string& k ) const
{
    std::cout << "cache_get: " << k << std::endl;
    return cache_.at( k );
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
