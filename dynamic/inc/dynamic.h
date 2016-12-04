#pragma once

#ifdef WIN32
	#ifdef Dynamic_EXPORTS
		#define MS_API __declspec(dllexport)
	#else
		#define MS_API __declspec(dllimport)
	#endif
#else
	#define MS_API
#endif

namespace pro {
	class dynamic
	{

	};
}