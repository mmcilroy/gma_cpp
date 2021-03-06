
header = {
    { id=1, name='type', type='fixed32' },
    { id=2, name='length', type='fixed32' }
}

place_order = {
    { id=1, name='user', type='string' },
    { id=2, name='clordid', type='string' },
    { id=3, name='symbol', type='string' },
    { id=4, name='side', type='string' },
    { id=5, name='ord_type', type='string' },
    { id=6, name='quantity', type='uint32' },
    { id=7, name='price', type='uint32' },
    { id=8, name='appendage', type='map<uint32,string>' }
}

order_executed = {
    { id=1, name='user', type='string' },
    { id=2, name='clordid', type='string' },
    { id=3, name='symbol', type='string' },
    { id=4, name='side', type='string' },
    { id=5, name='ord_type', type='string' },
    { id=6, name='quantity', type='uint32' },
    { id=7, name='price', type='uint32' },
    { id=8, name='ord_status', type='string' },
    { id=9, name='exec_type', type='string' },
    { id=10, name='last_qty', type='uint32' },
    { id=11, name='last_price', type='uint32' },
    { id=12, name='appendage', type='map<uint32,string>' }
}

update_cache = {
    { id=1, name='key', type='string' },
    { id=2, name='value', type='string' }
}

header_def = {
    id=0, eva='header', pb='Header'
}

message_def = {
    { id=1, eva='place_order', pb='PlaceOrder' },
    { id=2, eva='order_executed', pb='OrderExecuted' },
    { id=3, eva='update_cache', pb='UpdateCache' }
}
