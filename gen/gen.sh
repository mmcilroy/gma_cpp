rm -f ../proto/*
rm -f ../include/generated/*
rm -f ../src/generated/eva/pb/*

lua gen.lua

protoc --cpp_out=. *.proto

mv *.proto ../proto/
mv *.hpp ../include/generated/eva/
mv *.inl ../include/generated/eva/
mv *.pb.h ../include/generated/eva/pb/
mv *.pb.cc ../src/generated/eva/pb/
