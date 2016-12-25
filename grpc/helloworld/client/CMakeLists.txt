INCLUDE_DIRECTORIES(${CMAKE_CURRENT_SOURCE_DIR}/inc
					${CMAKE_CURRENT_SOURCE_DIR}/src
					${CMAKE_SOURCE_DIR}/util/inc
					${CMAKE_SOURCE_DIR}/dynamic/inc
					${CMAKE_SOURCE_DIR}/thirdparty/gRPC/include
					${CMAKE_SOURCE_DIR}/thirdparty/gRPC/third_party/protobuf/src
					)

FILE(GLOB GRPCS "src/*.pb.*")

ADD_EXECUTABLE(client inc/GreeterClient.h src/GreeterClient.cxx src/Main.cxx ${GRPCS})
ADD_EXECUTABLE(asyncclient inc/AsyncGreeterClient.h inc/MsgProc.h src/AsyncGreeterClient.cxx src/MsgProc.cxx src/AsyncMain.cxx ${GRPCS})
ADD_DEPENDENCIES(client dynamic utils)
ADD_DEPENDENCIES(asyncclient dynamic utils)

SET_TARGET_PROPERTIES(client PROPERTIES FOLDER "App/gRPC")
SET_TARGET_PROPERTIES(asyncclient PROPERTIES FOLDER "App/gRPC")

IF(CMAKE_SYSTEM_NAME MATCHES "Windows") 
	ADD_DEFINITIONS(/D"_WIN32_WINNT=0x601")
	TARGET_LINK_LIBRARIES(client dynamic utils gpr grpc grpc++ protoc protobuf eay32 ssleay32 zlib ws2_32)
	TARGET_LINK_LIBRARIES(asyncclient dynamic utils gpr grpc grpc++ protoc protobuf eay32 ssleay32 zlib ws2_32)
ELSE(CMAKE_SYSTEM_NAME MATCHES "Linux")
	TARGET_LINK_LIBRARIES(client dynamic utils gpr grpc grpc++ protoc protobuf eay32 ssleay32 zlib)
	TARGET_LINK_LIBRARIES(asyncclient dynamic utils gpr grpc grpc++ protoc protobuf eay32 ssleay32 zlib)
ENDIF(CMAKE_SYSTEM_NAME MATCHES "Windows")	
