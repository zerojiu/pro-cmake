#pragma once
#include <memory>
#include <grpc++/grpc++.h>
#include "app.grpc.pb.h"

using grpc::ServerCompletionQueue;
using grpc::Server;
using grpc::ServerBuilder;
using app::AsyncGreeter;

namespace pro {
	class AsyncGreeterService {
	public:
		explicit AsyncGreeterService();
		~AsyncGreeterService();

		void run(const std::string &addr);
		void handleRpcs();
	private:
		AsyncGreeter::AsyncService             _service;
		std::unique_ptr<ServerCompletionQueue> _cq;
		std::unique_ptr<Server>                _server;
	};
}