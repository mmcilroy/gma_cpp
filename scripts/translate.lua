
function translate_fix_to_place_order( cache, fix, po )

    -- set basic fields
    po:user( fix:get( 49 ) )
    po:clordid( fix:get( 11 ) )
    po:symbol( fix:get( 55 ) )
    po:side( fix:get( 54 ) )
    po:ord_type( fix:get( 40 ) )
    po:quantity( fix:get( 38 ) )
    po:price( fix:get( 44 ) )

    -- extend using configuration data
    po:appendage( 58, cache:get( "config.sys_id" ) )

    -- store configurable sticky tags
    for tag in string.gmatch( cache:get( "config.sticky_tags" ), "%d+" ) do
        cache:set( 'order.sticky.' .. tag .. '.' .. po:clordid(), fix:get( tag ) )
    end
end

function translate_order_executed_to_fix( cache, oe, fix )

    -- set basic fields
    fix:set( 11, oe:clordid() )
    fix:set( 55, oe:symbol() )
    fix:set( 54, oe:side() )
    fix:set( 40, oe:ord_type() )
    fix:set( 39, oe:ord_status() )
    fix:set( 150, oe:exec_type() )
    fix:set( 38, oe:quantity() )
    fix:set( 44, oe:price() )
    fix:set( 31, oe:last_price() )
    fix:set( 32, oe:last_qty() )

    -- extend using configuration data
    fix:set( 58, cache:get( "config.sys_id" ) )

    -- extend using function calls
    fix:set( 2001, util.time() )

    -- populate sticky tags
    for tag in string.gmatch( cache:get( "config.sticky_tags" ), "%d+" ) do
        fix:set( tag, cache:get( 'order.sticky.' .. tag .. '.' .. oe:clordid() ) )
    end
end
