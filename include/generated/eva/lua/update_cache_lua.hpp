#pragma once

#include "eva/event.hpp"

extern "C"
{
#include <lua.h>
#include <lauxlib.h>
#include <lualib.h>
}

const char* META_UPDATE_CACHE = "meta.update_cache";

int l_call_update_cache_key( lua_State* l )
{
    eva::update_cache* ev = *(eva::update_cache**)luaL_checkudata( l, 1, META_UPDATE_CACHE );
    size_t argc = lua_gettop( l );
    if( argc == 1 )
    {
        lua_pushstring( l, ev->key().c_str() );
        return 1;
    }
    else
    if( argc == 2 )
    {
        const char* val = luaL_checkstring( l, -1 );
        ev->key( val );
        return 0;
    }
    return 0;
}

int l_call_update_cache_value( lua_State* l )
{
    eva::update_cache* ev = *(eva::update_cache**)luaL_checkudata( l, 1, META_UPDATE_CACHE );
    size_t argc = lua_gettop( l );
    if( argc == 1 )
    {
        lua_pushstring( l, ev->value().c_str() );
        return 1;
    }
    else
    if( argc == 2 )
    {
        const char* val = luaL_checkstring( l, -1 );
        ev->value( val );
        return 0;
    }
    return 0;
}

void l_register_update_cache( lua_State* l )
{
    luaL_Reg reg[] =
    {
        { "key", l_call_update_cache_key },
        { "value", l_call_update_cache_value },
        { NULL, NULL }
    };
    luaL_newmetatable( l, META_UPDATE_CACHE );
    luaL_setfuncs( l, reg, 0 );
    lua_setfield( l, -1, "__index" );
}

int l_push_update_cache( lua_State* l, eva::update_cache& ev )
{
    eva::update_cache** udata = (eva::update_cache**)lua_newuserdata( l, sizeof( eva::update_cache* ) );
    *udata = &ev;
    luaL_getmetatable( l, META_UPDATE_CACHE );
    lua_setmetatable( l, -2 );
}

