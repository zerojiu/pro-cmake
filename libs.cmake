IF(CMAKE_SYSTEM_NAME MATCHES "Windows") 
	ADD_LIBRARY(gpr STATIC IMPORTED)
	ADD_LIBRARY(grpc STATIC IMPORTED)
	ADD_LIBRARY(grpc++ STATIC IMPORTED)
	ADD_LIBRARY(protoc STATIC IMPORTED)
	ADD_LIBRARY(protobuf STATIC IMPORTED)
	SET_TARGET_PROPERTIES(gpr PROPERTIES
     IMPORTED_LOCATION_RELEASE ${CMAKE_SOURCE_DIR}/thirdparty/gRPC/vsprojects/x64/release/gpr.lib
	 IMPORTED_LOCATION_DEBUG   ${CMAKE_SOURCE_DIR}/thirdparty/gRPC/vsprojects/x64/debug/gpr.lib)	
	SET_TARGET_PROPERTIES(grpc PROPERTIES
	 IMPORTED_LOCATION_RELEASE ${CMAKE_SOURCE_DIR}/thirdparty/gRPC/vsprojects/x64/release/grpc.lib
	 IMPORTED_LOCATION_DEBUG   ${CMAKE_SOURCE_DIR}/thirdparty/gRPC/vsprojects/x64/debug/grpc.lib)
	 SET_TARGET_PROPERTIES(grpc++ PROPERTIES
     IMPORTED_LOCATION_RELEASE ${CMAKE_SOURCE_DIR}/thirdparty/gRPC/vsprojects/x64/release/grpc++.lib
	 IMPORTED_LOCATION_DEBUG   ${CMAKE_SOURCE_DIR}/thirdparty/gRPC/vsprojects/x64/debug/grpc++.lib)	
	SET_TARGET_PROPERTIES(protoc PROPERTIES
	 IMPORTED_LOCATION_RELEASE ${CMAKE_SOURCE_DIR}/thirdparty/gRPC/third_party/protobuf/cmake/win/Release/libprotoc.lib
	 IMPORTED_LOCATION_DEBUG   ${CMAKE_SOURCE_DIR}/thirdparty/gRPC/third_party/protobuf/cmake/win/Debug/libprotoc.lib)
	 SET_TARGET_PROPERTIES(protobuf PROPERTIES
	 IMPORTED_LOCATION_RELEASE ${CMAKE_SOURCE_DIR}/thirdparty/gRPC/third_party/protobuf/cmake/win/Release/libprotobuf.lib
	 IMPORTED_LOCATION_DEBUG   ${CMAKE_SOURCE_DIR}/thirdparty/gRPC/third_party/protobuf/cmake/win/Debug/libprotobuf.lib)
	 
	EXECUTE_PROCESS(COMMAND  
        ${CMAKE_SOURCE_DIR}/thirdparty/gRPC/third_party/protobuf/cmake/win/Debug/protoc.exe 
        -I ${CMAKE_SOURCE_DIR}/protos/app 
        --grpc_out=${CMAKE_SOURCE_DIR}/app/src 
        --cpp_out=${CMAKE_SOURCE_DIR}/app/src 
        --plugin=protoc-gen-grpc=${CMAKE_SOURCE_DIR}/thirdparty/gRPC/vsprojects/x64/Debug/grpc_cpp_plugin.exe  
        ${CMAKE_SOURCE_DIR}/protos/app/app.proto)

ELSEIF(CMAKE_SYSTEM_NAME MATCHES "Linux")
	SET(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -static-libgcc  -static-libstdc++")

	ADD_LIBRARY(gpr STATIC IMPORTED)
	ADD_LIBRARY(grpc STATIC IMPORTED)
	ADD_LIBRARY(grpc++ STATIC IMPORTED)
	ADD_LIBRARY(protoc STATIC IMPORTED)
	ADD_LIBRARY(protobuf STATIC IMPORTED)
	SET_TARGET_PROPERTIES(gpr PROPERTIES IMPORTED_LOCATION ${CMAKE_SOURCE_DIR}/thirdparty/gRPC/libs/opt/libgpr.a)
	SET_TARGET_PROPERTIES(grpc PROPERTIES IMPORTED_LOCATION ${CMAKE_SOURCE_DIR}/thirdparty/gRPC/libs/opt/libgrpc.a)
	SET_TARGET_PROPERTIES(grpc++ PROPERTIES IMPORTED_LOCATION ${CMAKE_SOURCE_DIR}/thirdparty/gRPC/libs/opt/libgrpc++.a)	
	SET_TARGET_PROPERTIES(protoc PROPERTIES IMPORTED_LOCATION ${CMAKE_SOURCE_DIR}/thirdparty/gRPC/libs/opt/protobuf/libprotoc.a)
	SET_TARGET_PROPERTIES(protobuf PROPERTIES IMPORTED_LOCATION ${CMAKE_SOURCE_DIR}/thirdparty/gRPC/libs/opt/protobuf/libprotobuf.a)

IF(CMAKE_BUILD_TYPE MATCHES "Debug")	
	SET_TARGET_PROPERTIES(PocoFoundation PROPERTIES IMPORTED_LOCATION ${CMAKE_SOURCE_DIR}/thirdparty/libs/lib/libPocoFoundationd.a)
	SET_TARGET_PROPERTIES(PocoUtil PROPERTIES IMPORTED_LOCATION   ${CMAKE_SOURCE_DIR}/thirdparty/libs/lib/libPocoUtild.a)
	SET_TARGET_PROPERTIES(PocoXML PROPERTIES IMPORTED_LOCATION   ${CMAKE_SOURCE_DIR}/thirdparty/libs/lib/libPocoXMLd.a)	
	SET_TARGET_PROPERTIES(PocoJSON PROPERTIES IMPORTED_LOCATION   ${CMAKE_SOURCE_DIR}/thirdparty/libs/lib/libPocoJSONd.a)
ELSE()	
	SET_TARGET_PROPERTIES(PocoFoundation PROPERTIES IMPORTED_LOCATION ${CMAKE_SOURCE_DIR}/thirdparty/libs/lib/libPocoFoundation.a)
	SET_TARGET_PROPERTIES(PocoUtil PROPERTIES IMPORTED_LOCATION   ${CMAKE_SOURCE_DIR}/thirdparty/libs/lib/libPocoUtil.a)
	SET_TARGET_PROPERTIES(PocoXML PROPERTIES IMPORTED_LOCATION   ${CMAKE_SOURCE_DIR}/thirdparty/libs/lib/libPocoXML.a)	
	SET_TARGET_PROPERTIES(PocoJSON PROPERTIES IMPORTED_LOCATION   ${CMAKE_SOURCE_DIR}/thirdparty/libs/lib/libPocoJSON.a)
ENDIF(CMAKE_BUILD_TYPE MATCHES "Debug")
	
ENDIF(CMAKE_SYSTEM_NAME MATCHES "Windows")