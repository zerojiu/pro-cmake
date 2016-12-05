#include "GreeterService.h"
#include <memory>

void RunServer()
{
	std::string serverAddress("0.0.0.0:50051");
	pro::GreeterService service;

	ServerBuilder builder;
	builder.AddListeningPort(serverAddress, grpc::InsecureServerCredentials());
	builder.RegisterService(&service);
	std::unique_ptr<Server> server(builder.BuildAndStart());
	server->Wait();
}

int main(int argc, char* argv[])
{
	RunServer();

	return 0;
}