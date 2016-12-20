#pragma once
#include <memory>
#include <grpc++/grpc++.h>
#include "app.grpc.pb.h"

using grpc::Channel;
using grpc::ClientContext;
using grpc::Status;
using grpc::ClientAsyncResponseReader;
using grpc::CompletionQueue;
using app::HelloRequest;
using app::HelloResponse;
using app::AsyncGreeter;

namespace pro {
	class AsyncGreeterClient {
	public:
		AsyncGreeterClient(std::shared_ptr<Channel> channel)
		: _stub(AsyncGreeter::NewStub(channel)) { }
		~AsyncGreeterClient() = default;

		std::string sayHello(const std::string name);

	private:
		std::unique_ptr<AsyncGreeter::Stub> _stub;
	};
}