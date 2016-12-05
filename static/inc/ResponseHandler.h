#ifndef __STATIC_INC_REPLYHANDLER_H__
#define __STATIC_INC_REPLYHANDLER_H__

#include <string>

namespace pro {
	class ResponseHandler
	{
	public:
		ResponseHandler() = default;
		~ResponseHandler() = default;

		std::string getResponse(std::string request);
	};

	ResponseHandler* getResponseHandler();
}

#endif // __STATIC_INC_REPLYHANDLER_H__