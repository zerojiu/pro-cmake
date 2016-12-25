#include <memory>
#include <iostream>
#include "GreeterService.h"
#include "AsyncGreeterService.h"

void runAsyncServer()
{
	std::cout << "async server run." << std::endl;

	pro::AsyncGreeterService service;
	service.run("0.0.0.0:50052");
}

int main(int argc, char* argv[])
{
	runAsyncServer();

	return 0;
}