#ifndef __DYNAMIC_INC_DYNAMIC_H__
#define __DYNAMIC_INC_DYNAMIC_H__

#ifdef WIN32
	#ifdef Dynamic_EXPORTS
		#define MS_API __declspec(dllexport)
	#else
		#define MS_API __declspec(dllimport)
	#endif
#else
	#define MS_API
#endif

#include <string>

namespace pro {
	class MS_API RequestHandler
	{
	public:
		RequestHandler() = default;
		~RequestHandler() = default;

		std::string getRequest(std::string name);
	};

	MS_API RequestHandler* getRequestHandler();
}

#endif // __DYNAMIC_INC_DYNAMIC_H__

