#include "ResponseHandler.h"
#include "utils.h"

std::string pro::ResponseHandler::getResponse(std::string request)
{
	std::string greetWord = utils::getGreetWord();
	return std::string(greetWord + "," +  request);
}

pro::ResponseHandler* pro::getResponseHandler()
{
	static ResponseHandler* rh = new ResponseHandler;
	return rh;
}
