#pragma once

#include "eva/event.hpp"
#include <fstream>
#include <iostream>

namespace eva {

class journal
{
public:
    journal( const std::string&, bool );

    void write( const eva::event& );

    void flush();

    template< typename F >
    void recover( F );

private:
    std::fstream file_;
    std::string filename_;
};

#include "journal.inl"

}
