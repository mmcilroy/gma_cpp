#pragma once

#include "eva/event.hpp"

extern "C"
{
#include <lua.h>
#include <lauxlib.h>
#include <lualib.h>
}

const char* META_ORDER_EXECUTED = "meta.order_executed";

int l_call_order_executed_user( lua_State* l )
{
    eva::order_executed* ev = *(eva::order_executed**)luaL_checkudata( l, 1, META_ORDER_EXECUTED );
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

int l_call_order_executed_clordid( lua_State* l )
{
    eva::order_executed* ev = *(eva::order_executed**)luaL_checkudata( l, 1, META_ORDER_EXECUTED );
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

int l_call_order_executed_symbol( lua_State* l )
{
    eva::order_executed* ev = *(eva::order_executed**)luaL_checkudata( l, 1, META_ORDER_EXECUTED );
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

int l_call_order_executed_side( lua_State* l )
{
    eva::order_executed* ev = *(eva::order_executed**)luaL_checkudata( l, 1, META_ORDER_EXECUTED );
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

int l_call_order_executed_ord_type( lua_State* l )
{
    eva::order_executed* ev = *(eva::order_executed**)luaL_checkudata( l, 1, META_ORDER_EXECUTED );
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

int l_call_order_executed_quantity( lua_State* l )
{
    eva::order_executed* ev = *(eva::order_executed**)luaL_checkudata( l, 1, META_ORDER_EXECUTED );
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

int l_call_order_executed_price( lua_State* l )
{
    eva::order_executed* ev = *(eva::order_executed**)luaL_checkudata( l, 1, META_ORDER_EXECUTED );
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

int l_call_order_executed_ord_status( lua_State* l )
{
    eva::order_executed* ev = *(eva::order_executed**)luaL_checkudata( l, 1, META_ORDER_EXECUTED );
    size_t argc = lua_gettop( l );
    if( argc == 1 )
    {
        lua_pushstring( l, ev->ord_status().c_str() );
        return 1;
    }
    else
    if( argc == 2 )
    {
        const char* val = luaL_checkstring( l, -1 );
        ev->ord_status( val );
        return 0;
    }
    return 0;
}

int l_call_order_executed_exec_type( lua_State* l )
{
    eva::order_executed* ev = *(eva::order_executed**)luaL_checkudata( l, 1, META_ORDER_EXECUTED );
    size_t argc = lua_gettop( l );
    if( argc == 1 )
    {
        lua_pushstring( l, ev->exec_type().c_str() );
        return 1;
    }
    else
    if( argc == 2 )
    {
        const char* val = luaL_checkstring( l, -1 );
        ev->exec_type( val );
        return 0;
    }
    return 0;
}

int l_call_order_executed_last_qty( lua_State* l )
{
    eva::order_executed* ev = *(eva::order_executed**)luaL_checkudata( l, 1, META_ORDER_EXECUTED );
    size_t argc = lua_gettop( l );
    if( argc == 1 )
    {
        lua_pushinteger( l, ev->last_qty() );
        return 1;
    }
    else
    if( argc == 2 )
    {
        int val = luaL_checkinteger( l, -1 );
        ev->last_qty( val );
        return 0;
    }
    return 0;
}

int l_call_order_executed_last_price( lua_State* l )
{
    eva::order_executed* ev = *(eva::order_executed**)luaL_checkudata( l, 1, META_ORDER_EXECUTED );
    size_t argc = lua_gettop( l );
    if( argc == 1 )
    {
        lua_pushinteger( l, ev->last_price() );
        return 1;
    }
    else
    if( argc == 2 )
    {
        int val = luaL_checkinteger( l, -1 );
        ev->last_price( val );
        return 0;
    }
    return 0;
}

void l_register_order_executed( lua_State* l )
{
    luaL_Reg reg[] =
    {
        { "user", l_call_order_executed_user },
        { "clordid", l_call_order_executed_clordid },
        { "symbol", l_call_order_executed_symbol },
        { "side", l_call_order_executed_side },
        { "ord_type", l_call_order_executed_ord_type },
        { "quantity", l_call_order_executed_quantity },
        { "price", l_call_order_executed_price },
        { "ord_status", l_call_order_executed_ord_status },
        { "exec_type", l_call_order_executed_exec_type },
        { "last_qty", l_call_order_executed_last_qty },
        { "last_price", l_call_order_executed_last_price },
        { NULL, NULL }
    };
    luaL_newmetatable( l, META_ORDER_EXECUTED );
    luaL_setfuncs( l, reg, 0 );
    lua_setfield( l, -1, "__index" );
}

int l_push_order_executed( lua_State* l, eva::order_executed& ev )
{
    eva::order_executed** udata = (eva::order_executed**)lua_newuserdata( l, sizeof( eva::order_executed* ) );
    *udata = &ev;
    luaL_getmetatable( l, META_ORDER_EXECUTED );
    lua_setmetatable( l, -2 );
}

