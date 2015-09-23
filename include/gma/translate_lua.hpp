#pragma once

extern "C"
{
#include <lua.h>
#include <lauxlib.h>
#include <lualib.h>
}

#include "eva/lua/place_order_lua.hpp"
#include "eva/lua/order_executed_lua.hpp"

#include "fix/message.hpp"

#include "cache.hpp"

class translate_lua
{
public:
    translate_lua( cache& );

    void translate( const fix::field_map&, eva::place_order& );

    void translate( const eva::order_executed&, fix::field_map& );

private:
    lua_State* l;

    cache& cache_;
};

const char* META_UTIL = "meta.util";

int l_util_time( lua_State* l )
{
    char s[32];
    time_t t = time( 0 );
    struct tm* utc = gmtime( &t );
    sprintf( s, "%04d%02d%02d-%02d:%02d:%02d",
        utc->tm_year+1900,
        utc->tm_mon+1,
        utc->tm_mday,
        utc->tm_hour,
        utc->tm_min,
        utc->tm_sec );
    lua_pushstring( l, s );
    return 1;
}

void l_register_util( lua_State* l )
{
    luaL_Reg reg[] =
    {
        { "time", l_util_time },
        { NULL, NULL }
    };

    luaL_newmetatable( l, META_UTIL );
    luaL_setfuncs( l, reg, 0 );
    lua_pushvalue( l, -1 );
    lua_setfield( l, -1, "__index" );
    lua_setglobal(l, "util" );
}



const char* META_FIX = "meta.fix";

int l_fix_get( lua_State* l )
{
    fix::field_map* flds = *(fix::field_map**)luaL_checkudata( l, 1, META_FIX );
    int tag = luaL_checknumber( l, 2 );
    lua_pushstring( l, flds->at( tag ).c_str() );
    return 1;
}

int l_fix_set( lua_State* l )
{
    fix::field_map* flds = *(fix::field_map**)luaL_checkudata( l, 1, META_FIX );
    int tag = luaL_checknumber( l, 2 );
    const char* val = luaL_checkstring( l, 3 );
    (*flds)[ tag ] = val;
    return 0;
}

void l_push_fix( lua_State* l, const fix::field_map& flds )
{
    fix::field_map** udata = (fix::field_map**)lua_newuserdata( l, sizeof( fix::field_map* ) );
    *udata = &(fix::field_map&)flds;
    luaL_getmetatable( l, META_FIX );
    lua_setmetatable( l, -2 );
}

void l_register_fix( lua_State* l )
{
    luaL_Reg reg[] =
    {
        { "get", l_fix_get },
        { "set", l_fix_set },
        { NULL, NULL }
    };

    luaL_newmetatable( l, META_FIX );
    luaL_setfuncs( l, reg, 0 );
    lua_setfield( l, -1, "__index" );
}



const char* META_CACHE = "meta.cache";

int l_cache_get( lua_State* l )
{
    cache* c = *(cache**)luaL_checkudata( l, 1, META_CACHE );
    const char* k = luaL_checkstring( l, 2 );
    lua_pushstring( l, c->get( k ).c_str() );
    return 1;
}

int l_cache_set( lua_State* l )
{
    cache* c = *(cache**)luaL_checkudata( l, 1, META_CACHE );
    const char* k = luaL_checkstring( l, 2 );
    const char* v = luaL_checkstring( l, 3 );
    c->set( k, v );
    return 0;
}

void l_push_cache( lua_State* l, const cache& c )
{
    cache** udata = (cache**)lua_newuserdata( l, sizeof( cache* ) );
    *udata = &(cache&)c;
    luaL_getmetatable( l, META_CACHE );
    lua_setmetatable( l, -2 );
}

void l_register_cache( lua_State* l )
{
    luaL_Reg reg[] =
    {
        { "get", l_cache_get },
        { "set", l_cache_set },
        { NULL, NULL }
    };

    luaL_newmetatable( l, META_CACHE );
    luaL_setfuncs( l, reg, 0 );
    lua_setfield( l, -1, "__index" );
}



inline translate_lua::translate_lua( cache& c ) :
    l( luaL_newstate() ),
    cache_( c )
{
    luaL_openlibs( l );
    l_register_util( l );
    l_register_cache( l );
    l_register_fix( l );
    l_register_place_order( l );
    l_register_order_executed( l );

    int erred = luaL_dofile( l, "translate.lua" );
    if( erred ) {
        std::cout << "error: " << luaL_checkstring( l, -1 ) << std::endl;
    }
}

inline void translate_lua::translate( const fix::field_map& flds, eva::place_order& po )
{
    lua_getglobal( l, "translate_fix_to_place_order" );
    l_push_cache( l, cache_ );
    l_push_fix( l, flds );
    l_push_place_order( l, po );
    lua_call( l, 3, 0 );
}

inline void translate_lua::translate( const eva::order_executed& oe, fix::field_map& flds )
{
    lua_getglobal( l, "translate_order_executed_to_fix" );
    l_push_cache( l, cache_ );
    l_push_order_executed( l, (eva::order_executed&)oe );
    l_push_fix( l, flds );
    lua_call( l, 3, 0 );
}
