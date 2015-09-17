#pragma once

#include "eva/event.hpp"
#include <fstream>

namespace eva {

class journal
{
public:
    journal( const std::string& filename, bool truncate );

    void write( const eva::event& );

    void flush();

    template< typename F >
    void recover( F );

private:
    std::fstream file_;
    std::string filename_;
};

}



inline eva::journal::journal( const std::string& filename, bool truncate ) :
    filename_( filename )
{
    // create file if it does not exist
    if( truncate ) {
        std::ofstream( filename, std::ofstream::binary | std::ofstream::trunc );
    } else {
        std::ofstream( filename, std::ofstream::binary | std::ofstream::app );
    }

    // open file for binary rw operations
    file_.open( filename, std::fstream::in | std::fstream::out | std::fstream::binary );
    if( !file_.is_open() || !file_.good() ) {
        // error
    }
}

inline void eva::journal::write( const eva::event& ev )
{
    file_.seekp( 0, std::ios_base::end );
    file_.write( ev.get_header_buffer(), eva::EVENT_HEADER_SIZE + ev.length() );
    if( !file_.good() ) {
        // error
    }
}

inline void eva::journal::flush()
{
    file_.flush();
    if( !file_.good() ) {
        // error
    }
}

template< typename F >
inline void eva::journal::recover( F handler )
{
    std::fstream file;
    file.open( filename_, std::fstream::in | std::fstream::out | std::fstream::binary );
    if( file.is_open() && file.good() )
    {
        file.seekg( 0 );
        while( file.good() )
        {
            eva::event ev;

            // read the header
            file.read( ev.get_header_buffer(), eva::EVENT_HEADER_SIZE );
            if( !file.good() || !file.gcount() == eva::EVENT_HEADER_SIZE ) {
                return;
            }

            // read the payload
            size_t length = ev.length();
            file.read( ev.get_payload_buffer(), length );
            if( !file.good() || !file.gcount() == length ) {
                return;
            }

            handler( ev );
        }
    }
    else
    {
        // error
    }
}
