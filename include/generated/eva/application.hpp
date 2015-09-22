#pragma once

#include "eva/event.hpp"
#include "eva/journal.hpp"
#include "eva/replicate.hpp"

namespace eva {

class application
{
public:
    application();

    void recover();

    void inject( const place_order& );

    void inject( const order_executed& );

    void inject( const update_cache& );

    void join();

protected:
    virtual void process( const place_order&, bool ) { };

    virtual void process( const order_executed&, bool ) { };

    virtual void process( const update_cache&, bool ) { };

private:
    void jnl_thr_fn();

    void rep_thr_fn();

    void biz_thr_fn();

    journal journal_;

    replicate_master replicate_;

    event_publisher pub_;
    event_subscriber& jnl_sub_;
    event_subscriber& rep_sub_;
    event_subscriber& biz_sub_;

    std::thread jnl_thr_;
    std::thread rep_thr_;
    std::thread biz_thr_;
};

#include "application.inl"

}

