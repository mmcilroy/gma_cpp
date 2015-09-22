#include "eva/journal.hpp"

int main()
{
    eva::journal jnl( "journal.bin", false );

    jnl.recover( []( const eva::event& ev )
    {
        eva::event_type type = ev.type();

        if( type == eva::event_type::PLACE_ORDER )
        {
            ev.parse< eva::place_order >( [ & ]( const eva::place_order& msg ) {
                std::cout << msg << std::endl;
            } );
        }
        else
        if( type == eva::event_type::ORDER_EXECUTED )
        {
            ev.parse< eva::order_executed >( [ & ]( const eva::order_executed& msg ) {
                std::cout << msg << std::endl;
            } );
        }
        else
        if( type == eva::event_type::UPDATE_CACHE )
        {
            ev.parse< eva::update_cache >( [ & ]( const eva::update_cache& msg ) {
                std::cout << msg << std::endl;
            } );
        }
    } );
}
