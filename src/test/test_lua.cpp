extern "C"
{
#include <lua.h>
#include <lauxlib.h>
#include <lualib.h>
}

#include "fix/message.hpp"
#include "eva/lua/place_order_lua.hpp"



const char* FIX_META = "meta.fix";

int l_fix_get( lua_State* l )
{
    fix::field_map* fields = *(fix::field_map**)luaL_checkudata( l, 1, FIX_META );
    int tag = luaL_checknumber( l, 2 );
    lua_pushstring( l, fields->at( tag ).c_str() );
    return 1;
}

void l_register_fix( lua_State* l )
{
    luaL_Reg reg[] =
    {
        { "get", l_fix_get },
        { NULL, NULL }
    };

    luaL_newmetatable( l, FIX_META );
    luaL_setfuncs( l, reg, 0 );
    lua_setfield( l, -1, "__index" );
}



int main()
{
    lua_State* l = luaL_newstate();
    luaL_openlibs( l );
    l_register_fix( l );
    l_register_place_order( l );

    int erred = luaL_dofile( l, "test.lua" );
    if( erred ) {
        std::cout << "Lua error: " << luaL_checkstring( l, -1 ) << std::endl;
    }

    lua_getglobal( l, "test" );

    fix::field_map fields;
    fields[ 58 ] = "hi";
    fields[ 38 ] = 1;
    fix::field_map** udata1 = (fix::field_map**)lua_newuserdata( l, sizeof( fix::field_map* ) );
    *udata1 = &fields;
    luaL_getmetatable( l, FIX_META );
    lua_setmetatable( l, -2 );

    eva::place_order po;
    po.user( "there" );
    po.quantity( 999 );
    l_push_place_order( l, po );

    lua_call( l, 2, 0 );
    lua_close( l );

    std::cout << po.user() << std::endl;
    std::cout << po.quantity() << std::endl;
}
