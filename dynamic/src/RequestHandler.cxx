#include "RequestHandler.h"
#include "utils.h"

std::string pro::RequestHandler::getRequest(std::string name)
{
	std::string surname = utils::getSurname();
	return std::string(name + " " + surname);
}

MS_API pro::RequestHandler* pro::getRequestHandler()
{
	static RequestHandler* rh = new RequestHandler;
	return rh;
}

