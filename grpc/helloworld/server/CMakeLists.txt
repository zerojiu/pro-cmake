INCLUDE_DIRECTORIES(${CMAKE_CURRENT_SOURCE_DIR}/inc
					${CMAKE_CURRENT_SOURCE_DIR}/src
					${CMAKE_SOURCE_DIR}/util/inc
					${CMAKE_SOURCE_DIR}/dynamic/inc
					${CMAKE_SOURCE_DIR}/static/inc
					${CMAKE_SOURCE_DIR}/thirdparty/gRPC/include
					${CMAKE_SOURCE_DIR}/thirdparty/gRPC/third_party/protobuf/src
					)
FILE(GLOB GRPCS "src/*.pb.*")
SOURCE_GROUP("Generated Files" FILES ${GRPCS})

AUX_SOURCE_DIRECTORY(${CMAKE_CURRENT_SOURCE_DIR}/src DIR_SRCS)

FILE(GLOB INCS "inc/*.h")
FILE(GLOB HEADERS "src/*.h")
SOURCE_GROUP("Header Files" FILES ${INCS} ${HEADERS})

ADD_EXECUTABLE(server ${DIR_SRCS} ${HEADERS} ${INCS} ${GRPCS})
ADD_DEPENDENCIES(server static dynamic utils)

SET_TARGET_PROPERTIES(server PROPERTIES FOLDER "App/gRPC")

IF(CMAKE_SYSTEM_NAME MATCHES "Windows") 
	ADD_DEFINITIONS(/D"_WIN32_WINNT=0x601")
	TARGET_LINK_LIBRARIES(server static dynamic utils gpr grpc grpc++ protoc protobuf eay32 ssleay32 zlib ws2_32)
ELSE(CMAKE_SYSTEM_NME MATCHES "Linux")
	TARGET_LINK_LIBRARIES(server static dynamic utils gpr grpc grpc++ protoc protobuf eay32 ssleay32 zlib)
ENDIF(CMAKE_SYSTEM_NAME MATCHES "Windows")	
