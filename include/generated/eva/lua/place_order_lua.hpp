#pragma once

#include "eva/event.hpp"

extern "C"
{
#include <lua.h>
#include <lauxlib.h>
#include <lualib.h>
}

const char* META_PLACE_ORDER = "meta.place_order";

int l_call_place_order_user( lua_State* l )
{
    eva::place_order* ev = *(eva::place_order**)luaL_checkudata( l, 1, META_PLACE_ORDER );
    size_t argc = lua_gettop( l );
    if( argc == 1 )
    {
        lua_pushstring( l, ev->user().c_str() );
        return 1;
    }
    else
    if( argc == 2 )
    {
        const char* val = luaL_checkstring( l, -1 );
        ev->user( val );
        return 0;
    }
    return 0;
}

int l_call_place_order_clordid( lua_State* l )
{
    eva::place_order* ev = *(eva::place_order**)luaL_checkudata( l, 1, META_PLACE_ORDER );
    size_t argc = lua_gettop( l );
    if( argc == 1 )
    {
        lua_pushstring( l, ev->clordid().c_str() );
        return 1;
    }
    else
    if( argc == 2 )
    {
        const char* val = luaL_checkstring( l, -1 );
        ev->clordid( val );
        return 0;
    }
    return 0;
}

int l_call_place_order_symbol( lua_State* l )
{
    eva::place_order* ev = *(eva::place_order**)luaL_checkudata( l, 1, META_PLACE_ORDER );
    size_t argc = lua_gettop( l );
    if( argc == 1 )
    {
        lua_pushstring( l, ev->symbol().c_str() );
        return 1;
    }
    else
    if( argc == 2 )
    {
        const char* val = luaL_checkstring( l, -1 );
        ev->symbol( val );
        return 0;
    }
    return 0;
}

int l_call_place_order_side( lua_State* l )
{
    eva::place_order* ev = *(eva::place_order**)luaL_checkudata( l, 1, META_PLACE_ORDER );
    size_t argc = lua_gettop( l );
    if( argc == 1 )
    {
        lua_pushstring( l, ev->side().c_str() );
        return 1;
    }
    else
    if( argc == 2 )
    {
        const char* val = luaL_checkstring( l, -1 );
        ev->side( val );
        return 0;
    }
    return 0;
}

int l_call_place_order_ord_type( lua_State* l )
{
    eva::place_order* ev = *(eva::place_order**)luaL_checkudata( l, 1, META_PLACE_ORDER );
    size_t argc = lua_gettop( l );
    if( argc == 1 )
    {
        lua_pushstring( l, ev->ord_type().c_str() );
        return 1;
    }
    else
    if( argc == 2 )
    {
        const char* val = luaL_checkstring( l, -1 );
        ev->ord_type( val );
        return 0;
    }
    return 0;
}

int l_call_place_order_quantity( lua_State* l )
{
    eva::place_order* ev = *(eva::place_order**)luaL_checkudata( l, 1, META_PLACE_ORDER );
    size_t argc = lua_gettop( l );
    if( argc == 1 )
    {
        lua_pushinteger( l, ev->quantity() );
        return 1;
    }
    else
    if( argc == 2 )
    {
        int val = luaL_checkinteger( l, -1 );
        ev->quantity( val );
        return 0;
    }
    return 0;
}

int l_call_place_order_price( lua_State* l )
{
    eva::place_order* ev = *(eva::place_order**)luaL_checkudata( l, 1, META_PLACE_ORDER );
    size_t argc = lua_gettop( l );
    if( argc == 1 )
    {
        lua_pushinteger( l, ev->price() );
        return 1;
    }
    else
    if( argc == 2 )
    {
        int val = luaL_checkinteger( l, -1 );
        ev->price( val );
        return 0;
    }
    return 0;
}

int l_call_place_order_appendage( lua_State* l )
{
    eva::place_order* ev = *(eva::place_order**)luaL_checkudata( l, 1, META_PLACE_ORDER );
    size_t argc = lua_gettop( l );
    if( argc == 2 )
    {
        int k = luaL_checkinteger( l, -1 );
        lua_pushstring( l, ev->appendage( k ).c_str() );
        return 1;
    }
    else
    if( argc == 3 )
    {
        int k = luaL_checkinteger( l, -2 );
        const char* v = luaL_checkstring( l, -1 );
        ev->appendage( k, v );
        return 0;
    }
    return 0;
}

void l_register_place_order( lua_State* l )
{
    luaL_Reg reg[] =
    {
        { "user", l_call_place_order_user },
        { "clordid", l_call_place_order_clordid },
        { "symbol", l_call_place_order_symbol },
        { "side", l_call_place_order_side },
        { "ord_type", l_call_place_order_ord_type },
        { "quantity", l_call_place_order_quantity },
        { "price", l_call_place_order_price },
        { "appendage", l_call_place_order_appendage },
        { NULL, NULL }
    };
    luaL_newmetatable( l, META_PLACE_ORDER );
    luaL_setfuncs( l, reg, 0 );
    lua_setfield( l, -1, "__index" );
}

int l_push_place_order( lua_State* l, eva::place_order& ev )
{
    eva::place_order** udata = (eva::place_order**)lua_newuserdata( l, sizeof( eva::place_order* ) );
    *udata = &ev;
    luaL_getmetatable( l, META_PLACE_ORDER );
    lua_setmetatable( l, -2 );
}

