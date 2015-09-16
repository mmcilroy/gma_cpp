
rm -f include/messages/*
rm -f src/messages/*.pb.cc

cd messages

protoc --cpp_out=../include/messages *.proto

mv ../include/messages/*.cc ../src/messages

cd ..
