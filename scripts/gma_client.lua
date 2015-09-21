require 'util'

function on_event( sess, msg )
end

tcp = fix.tcp()
sess = tcp:connect( '0.0.0.0:14002', 'FIX.4.4', 'GSOR', 'GMA' )
sess:send( 'D', { { 11, '11111' }, { 38, 1 }, { 40, 1 }, { 44, 1 }, { 54, 1 }, { 55, 'VOD.L' }, { 60, fix.time() } } )

