#pragma once
#include "app.grpc.pb.h"
#include "AsyncGreeterClient.h"

using grpc::ClientAsyncReaderWriter;
using grpc::ClientAsyncResponseReader;
using grpc::ClientReaderWriter;
using app::AsyncGreeter;
using app::HelloRequest;
using app::HelloResponse;

namespace pro {
	class MsgProc {
	public:
		virtual void process() = 0;
		grpc::ClientContext _ctx;
		grpc::Status        _status;
	};

	class GreeterProc : public MsgProc{
	public:
		explicit GreeterProc(std::string &message, GreeterRspProcI *proc, void *userdata)
			: _proc(proc), _message(message), _userdata(userdata)
		{

		}
		virtual void process() override;
	private:
		friend class AsyncGreeterClient;
		GreeterRspProcI *_proc;
		HelloResponse    _rsp;
		std::string     &_message;
		void            *_userdata;
		std::unique_ptr<ClientAsyncResponseReader<HelloResponse>> _reader;
	};
}