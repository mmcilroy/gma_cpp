#pragma once

#include "pubsub/publisher.hpp"
#include "header.hpp"
#include "place_order.hpp"
#include "order_executed.hpp"
#include "update_cache.hpp"

namespace eva {

constexpr size_t EVENT_HEADER_SIZE = 10;
constexpr size_t EVENT_BUFFER_SIZE = 512;

enum event_type
{
    PLACE_ORDER,
    ORDER_EXECUTED,
    UPDATE_CACHE,
    END
};

class event
{
friend std::ostream& operator<<( std::ostream&, const event& );
public:
    char* buffer();

    const char* buffer() const;

    event_type type() const;

    size_t length() const;

    void parse( place_order& ) const;

    void serialize( const place_order& );

    void parse( order_executed& ) const;

    void serialize( const order_executed& );

    void parse( update_cache& ) const;

    void serialize( const update_cache& );

    template< typename T, typename F >
    void parse( F handler ) const;

private:
    template< typename T >
    void parse( event_type, T& ) const;

    template< typename T >
    void serialize( event_type, const T& );

    char buffer_[ EVENT_BUFFER_SIZE ];
};

typedef pubsub::publisher< event, pubsub::blocking_sequence > event_publisher;
typedef pubsub::subscriber< event, pubsub::blocking_sequence > event_subscriber;

#include "event.inl"

}

