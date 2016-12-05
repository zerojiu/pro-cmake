#ifndef __SERVER_INC_CLIENT_H__
#define __SERVER_INC_CLIENT_H__

#include <string>
#include <grpc++/grpc++.h>
#include "app.grpc.pb.h"

using grpc::Server;
using grpc::ServerBuilder;
using grpc::ServerContext;
using grpc::Status;
using app::HelloResponse;
using app::HelloRequest;
using app::Greeter;

namespace pro{
	class GreeterService : public Greeter::Service
	{
	public:
		GreeterService() = default;
		~GreeterService() = default;

		virtual Status sayHello(ServerContext* context, const HelloRequest* request, HelloResponse* response) override;
	};
}

#endif // __SERVER_INC_CLIENT_H__