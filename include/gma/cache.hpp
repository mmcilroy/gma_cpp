#pragma once

#include <map>
#include <string>

class cache
{
public:
    std::string get( const std::string& ) const;

    void set( const std::string&, const std::string& );

private:
    std::map< std::string, std::string > cache_;
};



std::string cache::get( const std::string& k ) const
{
    std::cout << "cache.get: " << k << std::endl;
    return cache_.at( k );
}

void cache::set( const std::string& k, const std::string& v )
{
    std::cout << "cache.set: " << k << " = " << v << std::endl;
    cache_[ k ] = v;
}
