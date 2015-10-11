#include <chrono>
#include <fstream>
#include <iostream>

const size_t B = 256;
const size_t N = 10 * 1024 * 1024;

int main()
{
    std::ofstream file( "journal.bin", std::ofstream::binary | std::ofstream::trunc );

    auto start = std::chrono::high_resolution_clock::now();

    char buf[ B ];
    for( auto i=1; i<=N; i++ )
    {
        file.seekp( 0, std::ios_base::end );
        file.write( buf, B );
        file.flush();
    }

    auto millis = std::chrono::duration_cast< std::chrono::milliseconds >(
        std::chrono::high_resolution_clock::now() - start ).count() + 1;

    auto messages_per_second = ( N * 1000 ) / millis;
    auto micros_per_message = 1000000 / messages_per_second;

    std::cout.imbue( std::locale( "" ) );
    std::cout << millis << " milliseconds" << std::endl;
    std::cout << messages_per_second << " messages per second" << std::endl;
    std::cout << micros_per_message << " microseconds per message" << std::endl;
}
