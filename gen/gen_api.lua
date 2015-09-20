
function gen_type( type )
    if type == 'string' then
        return 'std::string'
    elseif type == 'uint32' then
        return 'uint32_t'
    elseif type == 'fixed32' then
        return 'int32_t'
    else
        return "unknown_type"
    end
end

function gen_proto( msg )
    io.output( msg['pb'] .. '.proto' )
    io.write( 'syntax = "proto3";\n' )
    io.write( 'message ' .. msg['pb'] .. '\n' )
    io.write( '{\n' )
    for k, v in pairs( _G[msg['eva']] ) do
        io.write( '    ' .. v['type'] .. ' ' .. v['name'] .. ' = ' .. v['id'] .. ';\n' )
    end
    io.write( '}\n\n' )
end

function gen_eva_class( msg )

    io.output( msg['eva'] .. '.hpp' )
    io.write( '#pragma once\n\n' )
    io.write( '#include "eva/pb/' .. msg['pb'] .. '.pb.h"\n\n' )
    io.write( 'namespace eva {\n\n' )

    io.write( 'class ' .. msg['eva'] .. '\n' )
    io.write( '{\n' )
    io.write( 'friend std::ostream& operator<<( std::ostream&, const ' .. msg['eva'].. '& );\n' )
    io.write( 'public:\n' )

    for k, v in pairs( _G[msg['eva']] ) do
    if string.find( v['type'], "^map.*" ) then
    io.write( '    void ' .. v['name'] .. '( uint32_t, std::string );\n\n' )
    io.write( '    std::string ' .. v['name'] .. '( uint32_t );\n\n' )
    else
    io.write( '    void ' .. v['name'] .. '( ' .. gen_type( v['type'] ) .. ' );\n\n' )
    io.write( '    ' .. gen_type( v['type'] ) .. ' ' .. v['name'] .. '() const;\n\n' )
    end
    end

    io.write( '    size_t size() const;\n\n' )
    io.write( '    void parse( const std::string& );\n\n' )
    io.write( '    void serialize( std::string& ) const;\n\n')
    io.write( '    void parse( const char*, size_t );\n\n' )
    io.write( '    void serialize( char*, size_t ) const;\n\n')

    io.write( 'private:\n' )
    io.write( '    ' .. msg['pb'] .. ' pb_;\n' )
    io.write( '};\n\n' )
    io.write( '#include "' .. msg['eva'] .. '.inl"\n\n' )
    io.write( '}\n\n' )

    io.output( msg['eva'] .. '.inl' )

    io.write( 'inline std::ostream& operator<<( std::ostream& out, const ' .. msg['eva'] .. '& msg )\n' )
    io.write( '{\n' )
    io.write( '    out << msg.pb_.DebugString();\n' )
    io.write( '    return out;\n' )
    io.write( '}\n\n' )

    for k, v in pairs( _G[msg['eva']] ) do
    if string.find( v['type'], "^map.*" ) then

    io.write( 'inline void ' .. msg['eva'] .. '::' .. v['name'] .. '( uint32_t k, std::string v )\n' )
    io.write( '{\n' )
    io.write( '    (*pb_.mutable_' .. v['name'] .. '())[ k ] = v;\n' )
    io.write( '}\n\n' )

    io.write( 'inline std::string ' .. msg['eva'] .. '::' .. v['name'] .. '( uint32_t k )\n' )
    io.write( '{\n' )
    io.write( '    return (*pb_.mutable_' .. v['name'] .. '())[ k ];\n' )
    io.write( '}\n\n' )

    else

    io.write( 'inline void ' .. msg['eva'] .. '::' .. v['name'] .. '( ' .. gen_type( v['type'] ) .. ' v )\n' )
    io.write( '{\n' )
    io.write( '    pb_.set_' .. v['name'] .. '( v );\n' )
    io.write( '}\n\n' )

    io.write( 'inline ' .. gen_type( v['type'] ) .. ' ' .. msg['eva'] .. '::' .. v['name'] .. '() const\n' )
    io.write( '{\n' )
    io.write( '    return pb_.' .. v['name'] .. '();\n' )
    io.write( '}\n\n' )
    end
    end

    io.write( 'inline size_t ' .. msg['eva'] .. '::size() const\n' )
    io.write( '{\n' )
    io.write( '    return pb_.ByteSize();\n' )
    io.write( '}\n\n' )

    io.write( 'inline void ' .. msg['eva'] .. '::parse( const char* buf, size_t len )\n' )
    io.write( '{\n' )
    io.write( '    pb_.ParseFromArray( buf, len );\n')
    io.write( '}\n\n' )

    io.write( 'inline void ' .. msg['eva'] .. '::serialize( char* buf, size_t len ) const\n')
    io.write( '{\n' )
    io.write( '    pb_.SerializeToArray( buf, len );\n')
    io.write( '}\n\n' )
end

function gen_eva_event( msgs )

    io.output( 'event.hpp' )

    io.write( '#pragma once\n\n' )
    io.write( '#include "header.hpp"\n' )
    io.write( '#include "pulsar/publisher.hpp"\n' )
    for k,v in pairs( msgs ) do
    io.write( '#include "' .. v['eva'] .. '.hpp"\n' )
    end

    io.write( '\nnamespace eva {\n\n' )
    io.write( 'constexpr size_t EVENT_HEADER_SIZE = 10;\n' )
    io.write( 'constexpr size_t EVENT_BUFFER_SIZE = 256;\n\n' )

    io.write( 'enum event_type\n' )
    io.write( '{\n' )
    local i = 0
    for k,v in pairs( msgs ) do
    io.write( '    ' .. string.upper( v['eva'] ) )
    if i == 0 then
    io.write( ',\n' )
    else
    io.write( '\n' )
    end
    i = i + 1
    end
    io.write( '};\n\n' )

    io.write( 'class event\n' )
    io.write( '{\n' )
    io.write( 'public:\n' )
    io.write( '    event_type type() const;\n\n' )
    io.write( '    size_t length() const;\n\n' )

    for k,v in pairs( msgs ) do
    io.write( '    void parse( ' .. v['eva'] .. '& ) const;\n\n' )
    io.write( '    void serialize( const ' .. v['eva'] .. '& );\n\n' )
    end

    io.write( '    template< typename T, typename F >\n' )
    io.write( '    void parse( F handler ) const;\n\n' )

    io.write( 'private:\n' )
    io.write( '    template< typename T >\n' )
    io.write( '    void parse( event_type, T& ) const;\n\n' )
    io.write( '    template< typename T >\n' )
    io.write( '    void serialize( event_type, const T& );\n\n' )
    io.write( '    char buffer_[ EVENT_BUFFER_SIZE ];\n' )

    io.write( '};\n\n' )

    io.write( 'typedef pulsar::publisher< event, pulsar::blocking_sequence > event_publisher;\n' )
    io.write( 'typedef pulsar::subscriber< event, pulsar::blocking_sequence > event_subscriber;\n\n' )

    io.write( '#include "event.inl"\n\n' )
    io.write( '}\n\n' )

    io.output( 'event.inl' )

    io.write( 'inline event_type event::type() const\n' )
    io.write( '{\n' )
    io.write( '    header hdr;\n' )
    io.write( '    hdr.parse( buffer_, EVENT_HEADER_SIZE );\n' )
    io.write( '    return (event_type)hdr.type();\n' )
    io.write( '}\n\n' )

    io.write( 'inline size_t event::length() const\n' )
    io.write( '{\n' )
    io.write( '    header hdr;\n' )
    io.write( '    hdr.parse( buffer_, EVENT_HEADER_SIZE );\n' )
    io.write( '    return hdr.length();\n' )
    io.write( '}\n\n' )

    for k,v in pairs( msgs ) do
    io.write( 'inline void event::parse( ' .. v['eva'] .. '& msg ) const\n' )
    io.write( '{\n' )
    io.write( '    parse( event_type::' .. string.upper( v['eva'] ) .. ', msg );\n' )
    io.write( '}\n\n' )
    io.write( 'inline void event::serialize( const ' .. v['eva'] .. '& msg )\n' )
    io.write( '{\n' )
    io.write( '    serialize( event_type::' .. string.upper( v['eva'] ) .. ', msg );\n' )
    io.write( '}\n\n' )
    end

    io.write( 'template< typename T, typename F >\n' )
    io.write( 'inline void event::parse( F handler ) const\n' )
    io.write( '{\n' )
    io.write( '    T msg;\n' )
    io.write( '    parse( msg );\n' )
    io.write( '    handler( msg );\n' )
    io.write( '}\n\n' )

    io.write( 'template< typename T >\n' )
    io.write( 'inline void event::parse( event_type type, T& msg ) const\n' )
    io.write( '{\n' )
    io.write( '    header hdr;\n' )
    io.write( '    hdr.parse( buffer_, EVENT_HEADER_SIZE );\n' )
    io.write( '    if( hdr.type() == type ) {\n' )
    io.write( '        msg.parse( buffer_ + EVENT_HEADER_SIZE, hdr.length() );\n' )
    io.write( '    } else {\n' )
    io.write( '        // error!\n' )
    io.write( '    }\n' )
    io.write( '}\n\n' )

    io.write( 'template< typename T >\n' )
    io.write( 'inline void event::serialize( event_type type, const T& msg )\n' )
    io.write( '{\n' )
    io.write( '    header hdr;\n' )
    io.write( '    hdr.type( type );\n' )
    io.write( '    hdr.length( msg.size() );\n' )
    io.write( '    hdr.serialize( buffer_, EVENT_HEADER_SIZE );\n' )
    io.write( '    msg.serialize( buffer_ + EVENT_HEADER_SIZE, msg.size() );\n' )
    io.write( '}\n\n' )

end

function gen_eva_app( msgs )

    io.output( 'application.hpp' )

    io.write( '#pragma once\n\n' )
    io.write( '#include "eva/event.hpp"\n\n' )
    io.write( 'namespace eva {\n\n' )

    io.write( 'class application\n' )
    io.write( '{\n' )
    io.write( 'public:\n' )
    io.write( '    application();\n\n' )
    io.write( '    void join();\n\n' )

    for k,v in pairs( msgs ) do
    io.write( '    void inject( const ' .. v['eva'] .. '& );\n\n' )
    end

    io.write( 'protected:\n' )
    for k,v in pairs( msgs ) do
    io.write( '    virtual void process( const ' .. v['eva'] .. '&, bool ) { };\n\n' )
    end

    io.write( 'private:\n' )
    io.write( '    void jnl_thr_fn();\n\n' )
    io.write( '    void biz_thr_fn();\n\n' )

    io.write( '    event_publisher pub_;\n' )
    io.write( '    event_subscriber& jnl_sub_;\n' )
    io.write( '    event_subscriber& biz_sub_;\n\n' )

    io.write( '    std::thread jnl_thr_;\n' )
    io.write( '    std::thread biz_thr_;\n' )
    io.write( '};\n\n' )
    io.write( '#include "application.inl"\n\n' )
    io.write( '}\n\n' )

    io.output( 'application.inl' )

    io.write( 'inline application::application() :\n' )
    io.write( '    pub_( 8 ),\n' )
    io.write( '    jnl_sub_( pub_.subscribe() ),\n' )
    io.write( '    biz_sub_( jnl_sub_.subscribe() ),\n' )
    io.write( '    jnl_thr_( &application::jnl_thr_fn, this ),\n' )
    io.write( '    biz_thr_( &application::biz_thr_fn, this )\n' )
    io.write( '{\n' )

--[[
    io.write( '    journal jnl( "journal", false );\n' )
    io.write( '    jnl.recover( [ & ]( const event& ev )\n' )
    io.write( '    {\n' )
    io.write( '        event_type type = ev.type();\n' )
    local i=0
    for k,v in pairs( msgs ) do
    if i > 0 then
    io.write( '        else\n' )
    end
    io.write( '        if( type == event_type::' .. string.upper( v['eva'] ) .. ' )\n' )
    io.write( '        {\n' )
    io.write( '            ev.parse< ' .. v['eva'] .. ' >( [ & ]( const ' .. v['eva'] .. '& msg ) {\n' )
    io.write( '                process( msg, true );\n' )
    io.write( '            } );\n' )
    io.write( '        }\n' )
    i=i+1
    end
    io.write( '    } );\n' )
]]--
    io.write( '}\n\n' )

    for k,v in pairs( msgs ) do
    io.write( 'inline void application::inject( const ' .. v['eva'] .. '& msg )\n' )
    io.write( '{\n' )
    io.write( '    pub_.publish( 1, [ & ]( event& ev, size_t n ) {\n' )
    io.write( '        ev.serialize( msg );\n' )
    io.write( '    } );\n' )
    io.write( '}\n\n' )
    end

    io.write( 'inline void application::join()\n' )
    io.write( '{\n' )
    io.write( '    biz_thr_.join();\n' )
    io.write( '}\n\n' )

    io.write( 'inline void application::jnl_thr_fn()\n' )
    io.write( '{\n' )
    io.write( '    jnl_sub_.dispatch( [&]( const event& ev, size_t rem )\n' )
    io.write( '    {\n' )
    io.write( '        return false;\n' )
    io.write( '    } );\n' )
    io.write( '}\n\n' )

    io.write( 'inline void application::biz_thr_fn()\n' )
    io.write( '{\n' )
    io.write( '    biz_sub_.dispatch( [&]( const event& ev, size_t rem )\n' )
    io.write( '    {\n' )
    io.write( '        event_type type = ev.type();\n\n' )
    local i=0
    for k,v in pairs( msgs ) do
    if i > 0 then
    io.write( '        else\n' )
    end
    io.write( '        if( type == event_type::' .. string.upper( v['eva'] ) .. ' )\n' )
    io.write( '        {\n' )
    io.write( '            ev.parse< ' .. v['eva'] .. ' >( [ & ]( const ' .. v['eva'] .. '& msg ) {\n' )
    io.write( '                process( msg, false );\n' )
    io.write( '            } );\n' )
    io.write( '        }\n' )
    i=i+1
    end
    io.write( '\n' )
    io.write( '        return false;\n' )
    io.write( '    } );\n' )
    io.write( '}\n\n' )

end
