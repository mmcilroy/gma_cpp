require 'util'

function on_event( sess, msg )
end

tcp = fix.tcp()
sess = tcp:connect( '0.0.0.0:14002', 'FIX.4.4', 'GSOR', 'GMA' )
sess:send( 'D', { { 11, fix.id() }, { 38, 1 }, { 40, 1 }, { 44, 1 }, { 54, 1 }, { 55, 'VOD.L' }, { 60, fix.time() }, { 1001, 's1' }, { 1002, 's2' }, { 1003, 's3' } } )

