#include "eva/replicate.hpp"

int main()
{
    eva::replicate_slave rep( []( const eva::event& ev ) {
        std::cout << ev << std::endl;
    } );
    rep.join();
}
