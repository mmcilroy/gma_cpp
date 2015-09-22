rm -f ../proto/* > /dev/null 2>&1
rm -f ../include/generated/* > /dev/null 2>&1
rm -f ../src/generated/eva/pb/* > /dev/null 2>&1

lua gen.lua

protoc --cpp_out=. *.proto

mv *.proto ../proto/
mv *_lua.hpp ../include/generated/eva/lua/
mv *.hpp ../include/generated/eva/
mv *.inl ../include/generated/eva/
mv *.pb.h ../include/generated/eva/pb/
mv *.pb.cc ../src/generated/eva/pb/
