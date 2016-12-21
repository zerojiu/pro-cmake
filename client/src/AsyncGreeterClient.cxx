#include "AsyncGreeterClient.h"
#include "RequestHandler.h"
#include "MsgProc.h"

pro::AsyncGreeterClient::AsyncGreeterClient(std::shared_ptr<Channel> channel)
	: _stub(AsyncGreeter::NewStub(channel)), _running(true)
{
	_cq = new CompletionQueue;
	_runTr = std::thread(&pro::AsyncGreeterClient::run, this);
}

pro::AsyncGreeterClient::~AsyncGreeterClient()
{
	_running = false;
	_runTr.join();
}

std::string pro::AsyncGreeterClient::sayHello(const std::string name)
{
	HelloRequest req;
	req.set_name(pro::getRequestHandler()->getRequest(name));

	HelloResponse rsp;
	ClientContext ctx;

	Status status = _stub->sayHello(&ctx, req, &rsp);
	if (status.ok()) {
		return rsp.message();
	}
	else {
		return "RPC Failed.";
	}
}

void pro::AsyncGreeterClient::asyncSayHello(const std::string name, GreeterRspProcI *proc, void *userdata)
{
	GreeterProc *gp = new GreeterProc(_message, proc, userdata);
	HelloRequest req;
	req.set_name(pro::getRequestHandler()->getRequest(name));
	gp->_reader = _stub->AsyncsayHello(&gp->_ctx, req, _cq);
	gp->_reader->Finish(&gp->_rsp, &gp->_status, gp);
}

void pro::AsyncGreeterClient::run()
{
	void *tag = NULL;
	bool ok = false;
	grpc::CompletionQueue::NextStatus got = grpc::CompletionQueue::NextStatus::TIMEOUT;
	MsgProc* proc = NULL;
	gpr_timespec deadline;
	deadline.clock_type = GPR_TIMESPAN;
	deadline.tv_sec = 0;
	deadline.tv_nsec = 10000000;
	while (_running){
		if (_cq) {
			got = _cq->AsyncNext<gpr_timespec>(&tag, &ok, deadline);
			if (grpc::CompletionQueue::NextStatus::GOT_EVENT == got && ok) {
				proc = reinterpret_cast<MsgProc*>(tag);
				if (proc) {
					proc->process();
				}
			}
		}
	}
}
