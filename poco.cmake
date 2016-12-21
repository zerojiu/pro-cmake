IF(CMAKE_SYSTEM_NAME MATCHES "Windows") 
ADD_DEFINITIONS(/DPOCO_STATIC)
INCLUDE_DIRECTORIES(
	${CMAKE_SOURCE_DIR}/thirdparty/Poco/Foundation/include
	${CMAKE_SOURCE_DIR}/thirdparty/Poco/Util/include
	${CMAKE_SOURCE_DIR}/thirdparty/Poco/JSON/include
	${CMAKE_SOURCE_DIR}/thirdparty/Poco/Net/include
	${CMAKE_SOURCE_DIR}/thirdparty/Poco/Redis/include
	
)

LINK_DIRECTORIES(${CMAKE_SOURCE_DIR}/thirdparty/Poco/lib64)
ELSE() 
ADD_DEFINITIONS(-DPOCO_STATIC)
INCLUDE_DIRECTORIES(${CMAKE_SOURCE_DIR}/thirdparty/libs/include)
LINK_DIRECTORIES(${CMAKE_SOURCE_DIR}/thirdparty/libs/lib)
ENDIF(CMAKE_SYSTEM_NAME MATCHES "Windows")