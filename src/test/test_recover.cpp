#include "eva/journal.hpp"
#include <iostream>

int main()
{
    eva::journal jnl( "journal", false );
    jnl.recover( []( const eva::event& ev )
    {
        eva::event_type type = ev.type();
        if( ev.type() == eva::event_type::FIX_MESSAGE )
        {
            ev.parse< messages::FIXMessage >( [ & ]( const messages::FIXMessage& msg ) {
                std::cout << msg.DebugString() << std::endl;
            } );
        }
        else
        if( ev.type() == eva::event_type::XT_NEW_ORDER )
        {
            ev.parse< messages::XTNewOrder >( [ & ]( const messages::XTNewOrder& msg ) {
                std::cout << msg.DebugString() << std::endl;
            } );
        }
        else
        if( ev.type() == eva::event_type::XT_EXECUTION )
        {
            ev.parse< messages::XTExecution >( [ & ]( const messages::XTExecution& msg ) {
                std::cout << msg.DebugString() << std::endl;
            } );
        }
    } );
}
