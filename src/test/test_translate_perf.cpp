#include "translate_lua.hpp"
#include "translate_native.hpp"

const int N = 1000000;

int main()
{
    cache c;
    translate_lua l( c );
    translate_native n( c );

    fix::field_map flds;
    flds[ 49 ] = "GSOR";
    flds[ 11 ] = "12345";
    flds[ 55 ] = "VOD.L";
    flds[ 54 ] = "1";
    flds[ 40 ] = "1";
    flds[ 38 ] = "1";
    flds[ 44 ] = "1";

    eva::place_order po;

    std::cout.imbue( std::locale( "" ) );

    {
        auto start = std::chrono::high_resolution_clock::now();

        for( int i=0; i<N; i++ ) {
            n.translate( flds, po );
        }

        auto millis = std::chrono::duration_cast< std::chrono::milliseconds >(
            std::chrono::high_resolution_clock::now() - start ).count() + 1;

        std::cout << N << " native translations: " << ( N * 1000 ) / millis << " per second" << std::endl;
    }

    {
        auto start = std::chrono::high_resolution_clock::now();

        for( int i=0; i<N; i++ ) {
            l.translate( flds, po );
        }

        auto millis = std::chrono::duration_cast< std::chrono::milliseconds >(
            std::chrono::high_resolution_clock::now() - start ).count() + 1;

        std::cout << N << " lua translations: " << ( N * 1000 ) / millis << " per second" << std::endl;
    }
}
