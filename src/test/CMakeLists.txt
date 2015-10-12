add_executable( test_eva test_eva.cpp )
target_link_libraries( test_eva eva protobuf boost_system pthread )

add_executable( test_recover test_recover.cpp )
target_link_libraries( test_recover eva protobuf boost_system pthread )

add_executable( test_replicate test_replicate.cpp )
target_link_libraries( test_replicate eva protobuf boost_system pthread )

add_executable( test_lua test_lua.cpp )
target_link_libraries( test_lua eva protobuf lua5.2 )

add_executable( test_translate_perf test_translate_perf.cpp )
target_link_libraries( test_translate_perf eva protobuf lua5.2 )

add_executable( test_journal test_journal.cpp )
target_link_libraries( test_journal eva protobuf lua5.2 )
