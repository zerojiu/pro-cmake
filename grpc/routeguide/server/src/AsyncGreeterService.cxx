#include "AsyncGreeterService.h"
#include "MsgProc.h"

pro::AsyncGreeterService::AsyncGreeterService()
{

}

pro::AsyncGreeterService::~AsyncGreeterService()
{
	_server->Shutdown();
	_cq->Shutdown();
}

void pro::AsyncGreeterService::run(const std::string &addr)
{
	ServerBuilder builder;
	builder.AddListeningPort(addr, grpc::InsecureServerCredentials());
	builder.RegisterService(&_service);
	_cq = builder.AddCompletionQueue();
	_server = builder.BuildAndStart();

	handleRpcs();
}

void pro::AsyncGreeterService::handleRpcs()
{
	new AsyncGreeterProc(&_service, _cq.get());

	void *tag;
	bool ok;
	while (true) {
		if (_cq->Next(&tag, &ok) && ok) {
			static_cast<MsgProc*>(tag)->proceed();
		}
	}
}

