#include "GreeterClient.h"
#include "AsyncGreeterClient.h"

void runClient()
{
	pro::GreeterClient greeter(grpc::CreateChannel(
		"localhost:50051", grpc::InsecureChannelCredentials()));
	std::string user("John");
	std::string rsp = greeter.sayHello(user);
	std::cout << "Greeter Client Received: " << rsp << std::endl;

}

void runAsyncClient()
{
	pro::AsyncGreeterClient greeter(grpc::CreateChannel(
		"localhost:50052", grpc::InsecureChannelCredentials()));
	std::string user("John");
	std::string rsp = greeter.sayHello(user);
	std::cout << "AsyncGreeter Client Received: " << rsp << std::endl;
}

int main(int argc, char* argv[])
{
	runClient();

	runAsyncClient();

	return 0;
}