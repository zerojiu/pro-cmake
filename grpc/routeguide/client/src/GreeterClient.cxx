#include "GreeterClient.h"
#include "RequestHandler.h"

std::string pro::GreeterClient::sayHello(std::string user)
{
	HelloRequest req;
	req.set_name(pro::getRequestHandler()->getRequest(user));

	HelloResponse rsp;
	ClientContext ctx;
	
	Status status = _stub->sayHello(&ctx, req, &rsp);
	if (status.ok()) {
		return rsp.message();
	} else {
		return "RPC Failed.";
	}
}
