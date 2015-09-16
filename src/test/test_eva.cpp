
#include <iostream>
#include "eva/application.hpp"

class my_application : public eva::application
{
protected:
    virtual void process( const messages::FIXMessage& msg )
    {
        std::cout << msg.DebugString() << std::endl;
    }

    virtual void process( const messages::XTNewOrder& msg )
    {
        std::cout << msg.DebugString() << std::endl;
    }
};

int main()
{
    messages::XTNewOrder xt_new;
    xt_new.set_symbol( "VOD.L" );
    xt_new.set_side( "1" );
    xt_new.set_quantity( 100 );

    messages::FIXMessage fix_msg;
    fix_msg.set_message( "hi" );

    my_application app;
    app.inject( fix_msg );
    app.inject( xt_new );
    app.join();
}
