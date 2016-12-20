#include "AsyncGreeterClient.h"
#include "RequestHandler.h"

std::string pro::AsyncGreeterClient::sayHello(const std::string user)
{
	HelloRequest req;
	HelloResponse rsp;
	ClientContext ctx;
	CompletionQueue cq;
	Status status;

	req.set_name(pro::getRequestHandler()->getRequest(user));
	std::unique_ptr<ClientAsyncResponseReader<HelloResponse>> rpc(
		_stub->AsyncsayHello(&ctx, req, &cq));
	rpc->Finish(&rsp, &status, (void*)1);

	void *gotTag;
	bool ok = false;
	GPR_ASSERT(cq.Next(&gotTag, &ok));
	GPR_ASSERT(gotTag == (void*)1);
	GPR_ASSERT(ok);

	if (status.ok()) {
		return rsp.message();
	} else {
		return "RFC Failed.";
	}
}
