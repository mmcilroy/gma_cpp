#include <iostream>
#include "eva/application.hpp"
#include "fix/message.hpp"

class gma_application : public eva::application
{
public:
    void process( const messages::FIXMessage&, bool ) override;

    void process( const messages::XTExecution&, bool ) override;

protected:
    void process_new( const fix::message&, bool );

    void process_replace( const fix::message&, bool );

    void process_cancel( const fix::message&, bool );

    std::string cache_get( const std::string& ) const;

    void cache_set( const std::string&, const std::string& );

private:
    std::map< std::string, std::string > data_;
};


inline void gma_application::process( const messages::FIXMessage& msg, bool recovery )
{
    fix::message fix_msg( msg.message() );
    if( fix_msg.get( 35 ) == "D" ) {
        process_new( fix_msg, recovery );
    }
}

inline void gma_application::process_new( const fix::message& fix_msg, bool recovery )
{
    // get the xt and fix ids
    std::string xt_id = "67890";
    std::string fix_id = fix_msg.get( 11 );

    // store a mapping between them
    cache_set( "id.fix." + xt_id, fix_id );
    cache_set( "id.xt." + fix_id, xt_id );

    // remember the session we received the fix message from
    cache_set( "reply." + xt_id, fix_msg.get( 49 ) );

    if( !recovery )
    {
        // build the xt message
        messages::XTNewOrder xt_new;
        xt_new.set_clordid( xt_id );
        xt_new.set_symbol( fix_msg.get( 55 ) );
        xt_new.set_side( fix_msg.get( 54 ) );
        xt_new.set_ord_type( fix_msg.get( 40 ) );
        xt_new.set_quantity( fix_msg.get< int >( 38 ) );
        if( xt_new.ord_type() == "1" ) {
            xt_new.set_price( fix_msg.get< int >( 44 ) );
        }

        std::cout << xt_new.DebugString() << std::endl;
    }
}

inline void gma_application::process( const messages::XTExecution& xt_msg, bool recovery )
{
    if( !recovery )
    {
        // get the fix id
        std::string xt_id = xt_msg.clordid();
        std::string fix_id = cache_get( "id.fix." + xt_id );

        // build and send reply
        fix::message fix_msg;
        fix_msg.set( 35, "D" );
        fix_msg.set( 11, fix_id );
        fix_msg.set( 55, xt_msg.symbol() );
        fix_msg.set( 40, xt_msg.ord_type() );
        fix_msg.set( 38, xt_msg.quantity() );
        fix_msg.set( 44, xt_msg.ord_type() );

        std::cout << fix_msg << std::endl;
    }
}

inline std::string gma_application::cache_get( const std::string& k ) const
{
    std::cout << "cache_get: " << k << std::endl;
    return data_.at( k );
}

inline void gma_application::cache_set( const std::string& k, const std::string& v )
{
    std::cout << "cache_set: " << k << "=" << v << std::endl;
    data_[ k ] = v;
}

int main()
{
    messages::FIXMessage fix_msg;
    fix_msg.set_message( "49=SOR|35=D|11=12345|38=4|40=1|44=8|54=2|55=VOD.L|" );

    messages::XTExecution xt_exec;
    xt_exec.set_clordid( "67890" );
    xt_exec.set_symbol( "VOD.L" );
    xt_exec.set_side( "1" );
    xt_exec.set_ord_type( "1" );
    xt_exec.set_quantity( 1 );
    xt_exec.set_price( 1 );

    gma_application app;
    //app.inject( fix_msg );
    //app.inject( xt_exec );
    app.join();
}
