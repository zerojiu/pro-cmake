rPath=`pwd`
git submodule update --init --checkout

cd thirdparty
mkdir libs

cd $rPath/thirdparty/Poco
chmod 755 configure
chmod 755 build/script/*
./configure --prefix=$rPath/thirdparty/libs --no-tests --no-samples --static --omit=Data/MySQL,Data/ODBC,CppUnit,PageCompiler
make
make install

cd $rPath/thirdparty/gRPC
make

$rPath/thirdparty/gRPC/bins/opt/protobuf/protoc -I $rPath/grpc/protos/app --grpc_out=$rPath/grpc/helloworld/client/src --grpc_out=$rPath/grpc/helloworld/server/src --cpp_out=$rPath/grpc/helloworld/client/src --cpp_out=$rPath/grpc/helloworld/server/src --plugin=protoc-gen-grpc=$rPath/thirdparty/gRPC/bins/opt/grpc_cpp_plugin $rPath/grpc/protos/app/app.proto

mkdir $rPath/build/
mkdir $rPath/build/linux
cd $rPath/build/linux
cmake ../.. -G"Unix Makefiles"
make