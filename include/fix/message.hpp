#pragma once

#include <boost/tokenizer.hpp>
#include <boost/lexical_cast.hpp>
#include <boost/algorithm/string.hpp>
#include <vector>

namespace fix {

constexpr char delim_char = '|'; //(char)1;
constexpr char delim_str[] = { delim_char, (char)0 };

class message
{
public:
    message();

    message( const std::string& );

    void set( size_t tag, const std::string& val );

    template< typename T >
    void set( size_t tag, const T& val );

    std::string get( size_t tag ) const;

    template< typename T >
    T get( size_t tag ) const;

    std::string str() const;

private:
    std::map< int, std::string > fields_;
};

}



inline fix::message::message()
{
}

inline fix::message::message( const std::string& msg )
{
    static boost::char_separator< char > field_sep( delim_str );
    boost::tokenizer< boost::char_separator< char > > fields( msg, field_sep );
    for( auto field : fields )
    {
        std::vector< std::string > strs;
        boost::split( strs, field, boost::is_any_of( "=" ) );
        fields_[ boost::lexical_cast< int >( strs[0] ) ] = strs[1];
    }
}

inline void fix::message::set( size_t tag, const std::string& val )
{
    fields_[ tag ] = val;
}

template< typename T >
inline void fix::message::set( size_t tag, const T& val )
{
    set( tag, boost::lexical_cast< std::string >( val ) );
}

inline std::string fix::message::get( size_t tag ) const
{
    return fields_.at( tag );
}

template< typename T >
inline T fix::message::get( size_t tag ) const
{
    return boost::lexical_cast< T >( get( tag ) );
}

inline std::string fix::message::str() const
{
    std::stringstream ss;
    for( const auto& it : fields_ ) {
        ss << it.first << "=" << it.second << delim_str;
    }
    return ss.str();
}

inline std::ostream& operator<<( std::ostream& out, const fix::message& msg )
{
    out << msg.str();
    return out;
}
