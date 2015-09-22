#pragma once

#include "eva/pb/Header.pb.h"

namespace eva {

class header
{
friend std::ostream& operator<<( std::ostream&, const header& );
public:
    void type( int32_t );

    int32_t type() const;

    void length( int32_t );

    int32_t length() const;

    size_t size() const;

    void parse( const std::string& );

    void serialize( std::string& ) const;

    void parse( const char*, size_t );

    void serialize( char*, size_t ) const;

private:
    Header pb_;
};

#include "header.inl"

}

