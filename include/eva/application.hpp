
#include "eva/event.hpp"
#include "eva/journal.hpp"
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
    virtual void process( const messages::FIXMessage&, bool ) {}

    virtual void process( const messages::XTNewOrder&, bool ) {}

    virtual void process( const messages::XTExecution&, bool ) {}

    void jnl_thr_fn();

    void biz_thr_fn();

private:
    event_publisher pub_;
    event_subscriber& jnl_sub_;
    event_subscriber& biz_sub_;

    std::thread jnl_thr_;
    std::thread biz_thr_;
};

}



inline eva::application::application() :
    pub_( 8 ),
    jnl_sub_( pub_.subscribe() ),
    biz_sub_( jnl_sub_.subscribe() ),
    jnl_thr_( &application::jnl_thr_fn, this ),
    biz_thr_( &application::biz_thr_fn, this )
{
    eva::journal jnl( "journal", false );
    jnl.recover( [ & ]( const eva::event& ev )
    {
        eva::event_type type = ev.type();
        if( type == eva::event_type::FIX_MESSAGE )
        {
            ev.parse< messages::FIXMessage >( [ & ]( const messages::FIXMessage& msg ) {
                process( msg, true );
            } );
        }
        else
        if( type == eva::event_type::XT_NEW_ORDER )
        {
            ev.parse< messages::XTNewOrder >( [ & ]( const messages::XTNewOrder& msg ) {
                process( msg, true );
            } );
        }
        else
        if( type == eva::event_type::XT_EXECUTION )
        {
            ev.parse< messages::XTExecution >( [ & ]( const messages::XTExecution& msg ) {
                process( msg, true );
            } );
        }
    } );
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

inline void eva::application::jnl_thr_fn()
{
    eva::journal jnl( "journal", false );
    jnl_sub_.dispatch( [&]( const eva::event& ev, size_t rem )
    {
        jnl.write( ev );
        jnl.flush();

        return false;
    } );
}

inline void eva::application::biz_thr_fn()
{
    biz_sub_.dispatch( [&]( const eva::event& ev, size_t rem )
    {
        eva::event_type type = ev.type();
        if( type == eva::event_type::FIX_MESSAGE )
        {
            ev.parse< messages::FIXMessage >( [ & ]( const messages::FIXMessage& msg ) {
                process( msg, false );
            } );
        }
        else
        if( type == eva::event_type::XT_NEW_ORDER )
        {
            ev.parse< messages::XTNewOrder >( [ & ]( const messages::XTNewOrder& msg ) {
                process( msg, false );
            } );
        }
        else
        if( type == eva::event_type::XT_EXECUTION )
        {
            ev.parse< messages::XTExecution >( [ & ]( const messages::XTExecution& msg ) {
                process( msg, false );
            } );
        }

        return false;
    } );
}
