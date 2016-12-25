#include "GreeterClient.h"
#include "AsyncGreeterClient.h"

class GreeterRspProc : public pro::GreeterRspProcI {
public:
	virtual void onRsp(int32_t ec, void *userdata, std::string rsp)
	{
		if (ec == 0) {
			std::cout << "Greeter Client Received: " << rsp << std::endl;
		}
	}
};

void runClientAsyncService(pro::AsyncGreeterClient &greeter)
{
	std::string user("Peter");
	std::string rsp = greeter.sayHello(user);
	std::cout << "Greeter Client Received: " << rsp << std::endl;
}

void runAsyncCleintAsyncService(pro::AsyncGreeterClient &greeter)
{
	std::string user("Jack");
	GreeterRspProc proc;
	greeter.asyncSayHello(user, &proc, nullptr);
}

int main(int argc, char* argv[])
{
	pro::AsyncGreeterClient greeter(grpc::CreateChannel(
		"localhost:50052", grpc::InsecureChannelCredentials()));

	runClientAsyncService(greeter);

	runAsyncCleintAsyncService(greeter);

	getchar();

	return 0;
}