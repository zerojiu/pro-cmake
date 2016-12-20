#include <memory>
#include <thread>
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
void runAsyncServer()
{
	std::cout << "async server run." << std::endl;
	
	pro::AsyncGreeterService service;
	service.run("0.0.0.0:50052");
}

int main(int argc, char* argv[])
{
	std::thread serverThread(runServer);
	std::thread asyncServerThread(runAsyncServer);

	serverThread.join();
	asyncServerThread.join();

	return 0;
}