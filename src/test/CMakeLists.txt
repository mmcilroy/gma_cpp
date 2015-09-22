add_executable( test_eva test_eva.cpp )
target_link_libraries( test_eva eva protobuf boost_system pthread )

add_executable( test_recover test_recover.cpp )
target_link_libraries( test_recover eva protobuf boost_system pthread )

add_executable( test_replicate test_replicate.cpp )
target_link_libraries( test_replicate eva protobuf boost_system pthread )
