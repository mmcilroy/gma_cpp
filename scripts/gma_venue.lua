require 'util'

function on_event( sess, msg )
    msgtype = val( msg, 35 )
    if msgtype == 'A' then
        sess:send( 'A', { { 98, '0' }, { 108, '30' } } )
    elseif msgtype == '0' then
        sess:send( '0', {} )
    elseif msgtype == 'D' then
        sess:send( '8', {
            { 11, val( msg, 11 ) },
            { 55, val( msg, 55 ) },
            { 54, val( msg, 54 ) },
            { 40, val( msg, 40 ) },
            { 38, val( msg, 38 ) },
            { 44,  val( msg, 44 ) },
            { 39, 2 },
            { 150, "F" },
            { 31, val( msg, 44 ) },
            { 32, val( msg, 38 ) } } )
    end
end

tcp = fix.tcp()
tcp:accept( ':14003' )
