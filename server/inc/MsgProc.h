#pragma once
#include "grpc++/grpc++.h"
#include "app.grpc.pb.h"

using grpc::ServerCompletionQueue;
using grpc::ServerContext;
using grpc::Status;
using app::HelloRequest;
using app::HelloResponse;
using app::AsyncGreeter;

namespace pro {
	class MsgProc {
	public:
		MsgProc(AsyncGreeter::AsyncService *service, ServerCompletionQueue *cq)
			: _service(service), _cq(cq), _status(CREATE)
		{

		}
		virtual void proceed() = 0;
	protected:
		AsyncGreeter::AsyncService *_service;
		ServerCompletionQueue      *_cq;
		ServerContext               _ctx;

		enum CallStatus { CREATE, PROCESS, FINISH };
		CallStatus _status;
	};

	class AsyncGreeterProc : public MsgProc {
	public:
		AsyncGreeterProc(AsyncGreeter::AsyncService *service, ServerCompletionQueue *cq)
			: MsgProc(service, cq), _responder(&_ctx)
		{
			proceed();
		}
		virtual void proceed();
	private:
		HelloRequest  _req;
		HelloResponse _rsp;
		grpc::ServerAsyncResponseWriter<HelloResponse> _responder;
	};
}