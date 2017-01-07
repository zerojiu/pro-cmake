#include "GreeterClient.h"

void runClient()
{
	pro::GreeterClient greeter(grpc::CreateChannel(
		"localhost:50051", grpc::InsecureChannelCredentials()));
	std::string user("John");
	std::string rsp = greeter.sayHello(user);
	std::cout << "Greeter Client Received: " << rsp << std::endl;

}

int main(int argc, char* argv[])
{
	runClient();

	getchar();
	return 0;
}