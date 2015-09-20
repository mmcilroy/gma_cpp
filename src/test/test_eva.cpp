#include "eva/application.hpp"
#include <iostream>

class my_app : public eva::application
{
protected:
    void process( const eva::place_order& po, bool rec ) override {
        std::cout << po << std::endl;
    };

    void process( const eva::order_executed& oe, bool rec ) override {
        std::cout << oe << std::endl;
    };
};

int main()
{
    eva::place_order po;
    po.clordid( "12345" );
    po.appendage( 58, "hi" );

    my_app app;
    app.inject( po );
    app.join();
}
