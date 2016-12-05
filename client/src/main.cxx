#include "GreeterClient.h"

int main(int argc, char* argv[])
{
	pro::GreeterClient greeter(grpc::CreateChannel(
		"localhost:50051", grpc::InsecureChannelCredentials()));
	std::string user("John");
	std::string response = greeter.sayHello(user);
	std::cout << "Greeter Received: " << response << std::endl;

	return 0;
}