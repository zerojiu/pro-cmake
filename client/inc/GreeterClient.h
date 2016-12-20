#ifndef __CLIENT_INC_CLIENT_H__
#define __CLIENT_INC_CLIENT_H__

#include <memory>
#include <string>
#include <grpc++/grpc++.h>
#include "app.grpc.pb.h"

using grpc::Channel;
using grpc::ClientContext;
using grpc::Status;
using app::HelloRequest;
using app::HelloResponse;
using app::Greeter;

namespace pro {
	class GreeterClient
	{
	public:
		GreeterClient(std::shared_ptr<Channel> channel)
			: _stub(Greeter::NewStub(channel)) { }
		~GreeterClient() = default;

		std::string sayHello(const std::string name);

	private:
		std::unique_ptr<Greeter::Stub> _stub;
	};
}
#endif // __CLIENT_INC_CLIENT_H__