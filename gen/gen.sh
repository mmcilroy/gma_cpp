rm -f ../proto/*
rm -f ../include/eva/pb/*
rm -f ../include/eva/*
rm -f ../src/eva/pb/*

lua gen.lua

protoc --cpp_out=. *.proto

mv *.proto ../proto/
mv *.hpp ../include/eva/
mv *.inl ../include/eva/
mv *.pb.h ../include/eva/pb/
mv *.pb.cc ../src/eva/pb/
