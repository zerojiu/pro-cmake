INCLUDE_DIRECTORIES(${CMAKE_CURRENT_SOURCE_DIR}/inc
					${CMAKE_CURRENT_SOURCE_DIR}/src
					${CMAKE_SOURCE_DIR}/util/inc
					${CMAKE_SOURCE_DIR}/dynamic/inc
					${CMAKE_SOURCE_DIR}/thirdparty/gRPC/include
					${CMAKE_SOURCE_DIR}/thirdparty/gRPC/third_party/protobuf/src
					)
					
AUX_SOURCE_DIRECTORY(${CMAKE_CURRENT_SOURCE_DIR}/src DIR_SRCS)

FILE(GLOB INCS "inc/*.h")
FILE(GLOB HEADERS "src/*.h")
SOURCE_GROUP("Header Files" FILES ${INCS} ${HEADERS})

ADD_EXECUTABLE(pocotest ${DIR_SRCS} ${HEADERS} ${INCS})
ADD_DEPENDENCIES(pocotest utils)

SET_TARGET_PROPERTIES(pocotest PROPERTIES FOLDER "Test")

IF(CMAKE_SYSTEM_NAME MATCHES "Windows") 
	ADD_DEFINITIONS(/D"_WIN32_WINNT=0x601")
	TARGET_LINK_LIBRARIES(pocotest utils gpr grpc grpc++ protoc protobuf eay32 ssleay32 zlib ws2_32)
ELSE(CMAKE_SYSTEM_NAME MATCHES "Linux")
	TARGET_LINK_LIBRARIES(app utils PocoUtil PocoXML PocoJSON PocoFoundation gpr grpc grpc++ protoc protobuf z ssl crypto pthread)
ENDIF(CMAKE_SYSTEM_NAME MATCHES "Windows")	
