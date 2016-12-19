#include "GreeterClient.h"
#include "RequestHandler.h"

std::string pro::GreeterClient::sayHello(std::string user)
{
	HelloRequest request;
	request.set_name(pro::getRequestHandler()->getRequest(user));

	HelloResponse response;
	ClientContext context;
	
	Status status = _stub->sayHello(&context, request, &response);
	if (status.ok()) {
		return response.message();
	} else {
		return "RPC Failed.";
	}
}
