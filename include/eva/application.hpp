
#include "eva/event.hpp"
#include "pulsar/publisher.hpp"

namespace eva {

typedef pulsar::publisher< eva::event, pulsar::blocking_sequence > event_publisher;
typedef pulsar::subscriber< eva::event, pulsar::blocking_sequence > event_subscriber;

class application
{
public:
    application();

    template< typename T >
    void inject( const T& );

    void join();

protected:
    virtual void process( const messages::FIXMessage& ) {}

    virtual void process( const messages::XTNewOrder& ) {}

    virtual void process( const messages::XTExecution& ) {}

    void biz_thr_fn();

private:
    event_publisher pub_;
    event_subscriber& biz_sub_;

    std::thread biz_thr_;
};

}



inline eva::application::application() :
    pub_( 8 ),
    biz_sub_( pub_.subscribe() ),
    biz_thr_( &application::biz_thr_fn, this )
{
}

template< typename T >
inline void eva::application::inject( const T& msg )
{
    pub_.publish( 1, [ & ]( eva::event& ev, size_t n ) {
        ev.serialize( msg );
    } );
}

inline void eva::application::join()
{
    biz_thr_.join();
}

inline void eva::application::biz_thr_fn()
{
    biz_sub_.dispatch( [&]( const eva::event& ev, size_t rem )
    {
        if( ev.type() == eva::event_type::FIX_MESSAGE )
        {
            ev.parse< messages::FIXMessage >( [ & ]( const messages::FIXMessage& msg ) {
                process( msg );
            } );
        }
        else
        if( ev.type() == eva::event_type::XT_NEW_ORDER )
        {
            ev.parse< messages::XTNewOrder >( [ & ]( const messages::XTNewOrder& msg ) {
                process( msg );
            } );
        }
        else
        if( ev.type() == eva::event_type::XT_EXECUTION )
        {
            ev.parse< messages::XTExecution >( [ & ]( const messages::XTExecution& msg ) {
                process( msg );
            } );
        }

        return false;
    } );
}
