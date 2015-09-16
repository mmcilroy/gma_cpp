#include "XTNewOrder.pb.h"

namespace xt {

class session
{
public:
    virtual std::optional< std::string > new_order( const messages::XTNewOrder& ) = 0;
};

class lse_session : public session
{
public:
    std::optional< std::string > new_order( 
        const std::string& symbol,
        const std::string& account,
        lse::side,
        lse::ord_type,
        lse::capacity,
        lse::time_in_force,
        uint32_t quantity,
        std::optional< uint32_t > price
    );

    virtual std::optional< std::string > new_order( const messages::XTNewOrder& );
};

class lse
{
public:
};

}


int main()
{
    xt::session* xt_session = xt_.get_session( "lse" );

    messages::XTNewOrder xt_new;
    xt_msg.set_clordid( xt_id );
    xt_msg.set( "symbol", fix_msg.get( 55 ) );
    xt_msg.set( "ordtype", fix_msg.get( 40 ) );
    xt_msg.set( "ordqty", fix_msg.get( 38 ) );

    xt_session->send( xt_new );
}
