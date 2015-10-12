cmake_minimum_required( VERSION 2.8 )
project( gma_cpp )
set( VERSION_NUMBER "0.0.1" )

if( "${CMAKE_BUILD_TYPE}" STREQUAL "Release" )
    set( VERSION "${VERSION_NUMBER}-release" )
else()
    set( VERSION "${VERSION_NUMBER}-debug" )
endif()

set( CMAKE_CXX_FLAGS  "${CMAKE_CXX_FLAGS} -std=c++11 -Wl,--no-as-needed -O3" )

include_directories( include include/gma include/generated include/generated/eva/pb /usr/include/lua5.2 )
include_directories( $ENV{HOME}/pubsub_cpp/include )
include_directories( $ENV{HOME}/fix_cpp/include )

add_subdirectory( src )
