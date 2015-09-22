inline journal::journal( const std::string& filename, bool truncate ) :
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

inline void journal::write( const eva::event& ev )
{
    std::cout << "journal.write " << ev.length() + EVENT_HEADER_SIZE << std::endl;

    file_.seekp( 0, std::ios_base::end );
    file_.write( ev.buffer(), ev.length() + EVENT_HEADER_SIZE );
    if( !file_.good() ) {
        // error
    }
}

inline void journal::flush()
{
    file_.flush();
    if( !file_.good() ) {
        // error
    }
}

template< typename F >
inline void journal::recover( F handler )
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
            file.read( ev.buffer(), EVENT_HEADER_SIZE );
            if( !file.good() || !file.gcount() == EVENT_HEADER_SIZE ) {
                return; // error
            }

            // read the payload
            size_t length = ev.length();
            file.read( ev.buffer() + EVENT_HEADER_SIZE, length );
            if( !file.good() || !file.gcount() == length ) {
                return; // error
            }

            std::cout << "journal.recover " << length + EVENT_HEADER_SIZE << std::endl;

            handler( ev );
        }
    }
}
