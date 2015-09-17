#pragma once

#include "eva/event_types.hpp"

#include "messages/Header.pb.h"
#include "messages/FIXMessage.pb.h"
#include "messages/XTNewOrder.pb.h"
#include "messages/XTExecution.pb.h"

namespace eva {

constexpr size_t EVENT_HEADER_SIZE = 10;
constexpr size_t EVENT_BUFFER_SIZE = 256;

class event
{
public:
    eva::event_type type() const;

    size_t length() const;

    char* get_header_buffer() const;

    char* get_payload_buffer() const;

    template< typename T, typename F >
    void parse( F ) const;

    void parse( messages::FIXMessage& ) const;

    void parse( messages::XTNewOrder& ) const;

    void parse( messages::XTExecution& ) const;

    void serialize( const messages::FIXMessage& );

    void serialize( const messages::XTNewOrder& );

    void serialize( const messages::XTExecution& );

private:
    template< typename T >
    void parse( eva::event_type, T& ) const;

    template< typename T >
    void serialize( eva::event_type, const T& );

    char buffer_[ eva::EVENT_BUFFER_SIZE ];
};

}



inline eva::event_type eva::event::type() const
{
    messages::Header hdr;
    hdr.ParseFromArray( buffer_, EVENT_HEADER_SIZE );
    return (eva::event_type)hdr.type();
}

inline size_t eva::event::length() const
{
    messages::Header hdr;
    hdr.ParseFromArray( buffer_, EVENT_HEADER_SIZE );
    return hdr.length();
}

inline char* eva::event::get_header_buffer() const
{
    return (char*)buffer_;
}

inline char* eva::event::get_payload_buffer() const
{
    return (char*)buffer_ + EVENT_HEADER_SIZE;
}

template< typename T, typename F >
inline void eva::event::parse( F handler ) const
{
    T msg;
    parse( msg );
    handler( msg );
}

inline void eva::event::parse( messages::FIXMessage& msg ) const
{
    parse( eva::event_type::FIX_MESSAGE, msg );
}

inline void eva::event::parse( messages::XTNewOrder& msg ) const
{
    parse( eva::event_type::XT_NEW_ORDER, msg );
}

inline void eva::event::parse( messages::XTExecution& msg ) const
{
    parse( eva::event_type::XT_EXECUTION, msg );
}

template< typename T >
inline void eva::event::parse( eva::event_type type, T& msg ) const
{
    messages::Header hdr;
    hdr.ParseFromArray( buffer_, EVENT_HEADER_SIZE );
    if( hdr.type() == type ) {
        msg.ParseFromArray( buffer_ + hdr.ByteSize(), hdr.length() );
    } else {
        // error!
    }
}

inline void eva::event::serialize( const messages::FIXMessage& msg )
{
    serialize( eva::event_type::FIX_MESSAGE, msg );
}

inline void eva::event::serialize( const messages::XTNewOrder& msg )
{
    serialize( eva::event_type::XT_NEW_ORDER, msg );
}

inline void eva::event::serialize( const messages::XTExecution& msg )
{
    serialize( eva::event_type::XT_EXECUTION, msg );
}

template< typename T >
inline void eva::event::serialize( eva::event_type type, const T& msg )
{
    messages::Header hdr;
    hdr.set_type( type );
    hdr.set_length( msg.ByteSize() );
    hdr.SerializeToArray( buffer_, hdr.ByteSize() );
    msg.SerializeToArray( buffer_ + hdr.ByteSize(), msg.ByteSize() );
}
