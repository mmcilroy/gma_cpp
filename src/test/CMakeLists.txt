add_executable( test_eva test_eva.cpp )
target_link_libraries( test_eva messages protobuf pthread )

add_executable( test_recover test_recover.cpp )
target_link_libraries( test_recover messages protobuf pthread )

add_executable( test_selene test_selene.cpp )
target_link_libraries( test_selene messages protobuf lua5.2 pthread )
