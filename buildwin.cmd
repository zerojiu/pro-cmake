setlocal

@rem add git to system environmental variables
git submodule update --init --recursive

cd tools
nuget restore ../thirdparty/gRPC/vsprojects/grpc.sln
cd %~dp0

devenv thirdparty/gRPC/vsprojects/grpc.sln /Build "Debug|x64"
devenv thirdparty/gRPC/vsprojects/grpc.sln /Build "Release|x64"

cd thirdparty/gRPC/third_party/protobuf/cmake
mkdir win
cd win
cmake -G"Visual Studio 14 2015 Win64"
devenv protobuf.sln /Build "Debug|x64"
devenv protobuf.sln /Build "Release|x64"

cd %~dp0
devenv thirdparty/gRPC/vsprojects/grpc_protoc_plugins.sln /Build "Debug|x64"
devenv thirdparty/gRPC/vsprojects/grpc_protoc_plugins.sln /Build "Release|x64"

cd %~dp0
mkdir build
cd build
mkdir win
cd win
cmake ../.. -G"Visual Studio 14 2015 Win64"