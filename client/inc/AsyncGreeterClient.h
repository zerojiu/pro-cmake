#pragma once
#include <memory>
#include <thread>
#include <atomic>
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
	class GreeterRspProcI {
	public:
		virtual void onRsp(int32_t ec, void *userdata, std::string rsp) = 0;
	};

	class AsyncGreeterClient {
	public:
		AsyncGreeterClient(std::shared_ptr<Channel> channel);

		~AsyncGreeterClient();

		std::string sayHello(const std::string name);

		void asyncSayHello(const std::string name, GreeterRspProcI *proc, void *userdata);
		
	private:
		void run();

	private:
		std::unique_ptr<AsyncGreeter::Stub> _stub;
		CompletionQueue                    *_cq;
		std::string                         _message;
		std::thread                         _runTr;
		std::atomic<bool>                   _running;
	};
}