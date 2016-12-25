#include <memory>
#include <iostream>
#include "GreeterService.h"
#include "AsyncGreeterService.h"

void runServer()
{
	std::cout << "server run." << std::endl;

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
	runServer();

	return 0;
}