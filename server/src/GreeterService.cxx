#include "GreeterService.h"
#include "ResponseHandler.h"

Status pro::GreeterService::sayHello(ServerContext* context, const HelloRequest* request, HelloResponse* response)
{
	response->set_message(pro::getResponseHandler()->getResponse(request->name()));
	return Status::OK;
}