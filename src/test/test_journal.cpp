#include "eva/journal.hpp"
#include <chrono>
#include <iostream>

const size_t N = 1024 * 1024;

int main()
{
    eva::journal j( "journal.bin", true );
    eva::event e;

    auto start = std::chrono::high_resolution_clock::now();

    for( auto i=1; i<=N; i++ )
    {
        j.write( e );
        j.flush();
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
