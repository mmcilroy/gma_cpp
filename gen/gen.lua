require 'gen_api'
require 'gen_data'

gen_proto( header_def )
gen_eva_class( header_def )

for k,v in pairs( message_def ) do
    gen_proto( v )
    gen_eva_class( v )
end

gen_eva_event( message_def )
gen_eva_app( message_def )