#pragma once

#include "eva/pb/UpdateCache.pb.h"

namespace eva {

class update_cache
{
friend std::ostream& operator<<( std::ostream&, const update_cache& );
public:
    void key( std::string );

    std::string key() const;

    void value( std::string );

    std::string value() const;

    size_t size() const;

    void parse( const std::string& );

    void serialize( std::string& ) const;

    void parse( const char*, size_t );

    void serialize( char*, size_t ) const;

private:
    UpdateCache pb_;
};

#include "update_cache.inl"

}

