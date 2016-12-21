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
	 
	 #使用grpc项目通过NUGET获取的openssl库和zlib库
	ADD_LIBRARY(eay32 SHARED IMPORTED)
	SET_PROPERTY(TARGET eay32 PROPERTY IMPORTED_IMPLIB_DEBUG ${CMAKE_SOURCE_DIR}/thirdparty/gRPC/vsprojects/packages/grpc.dependencies.openssl.1.0.204.1/build/native/lib/v140/x64/Debug/dynamic/libeay32.lib)
	SET_PROPERTY(TARGET eay32 PROPERTY IMPORTED_LOCATION_DEBUG  ${CMAKE_SOURCE_DIR}/thirdparty/gRPC/vsprojects/packages/grpc.dependencies.openssl.redist.1.0.204.1/build/native/bin/v140/x64/Debug/dynamic/libeay32.dll)
	SET_PROPERTY(TARGET eay32 PROPERTY IMPORTED_IMPLIB_RELEASE ${CMAKE_SOURCE_DIR}/thirdparty/gRPC/vsprojects/packages/grpc.dependencies.openssl.1.0.204.1/build/native/lib/v140/x64/Release/dynamic/libeay32.lib)
	SET_PROPERTY(TARGET eay32 PROPERTY IMPORTED_LOCATION_RELEASE  ${CMAKE_SOURCE_DIR}/thirdparty/gRPC/vsprojects/packages/grpc.dependencies.openssl.redist.1.0.204.1/build/native/bin/v140/x64/Release/dynamic/libeay32.dll)
	
	ADD_LIBRARY(ssleay32 SHARED IMPORTED)
	SET_PROPERTY(TARGET ssleay32 PROPERTY IMPORTED_IMPLIB_DEBUG ${CMAKE_SOURCE_DIR}/thirdparty/gRPC/vsprojects/packages/grpc.dependencies.openssl.1.0.204.1/build/native/lib/v140/x64/Debug/dynamic/ssleay32.lib)
	SET_PROPERTY(TARGET ssleay32 PROPERTY IMPORTED_LOCATION_DEBUG  ${CMAKE_SOURCE_DIR}/thirdparty/gRPC/vsprojects/packages/grpc.dependencies.openssl.redist.1.0.204.1/build/native/bin/v140/x64/Debug/dynamic/ssleay32.dll)
	SET_PROPERTY(TARGET ssleay32 PROPERTY IMPORTED_IMPLIB_RELEASE ${CMAKE_SOURCE_DIR}/thirdparty/gRPC/vsprojects/packages/grpc.dependencies.openssl.1.0.204.1/build/native/lib/v140/x64/Release/dynamic/ssleay32.lib)
	SET_PROPERTY(TARGET ssleay32 PROPERTY IMPORTED_LOCATION_RELEASE  ${CMAKE_SOURCE_DIR}/thirdparty/gRPC/vsprojects/packages/grpc.dependencies.openssl.redist.1.0.204.1/build/native/bin/v140/x64/Release/dynamic/ssleay32.dll)

	ADD_LIBRARY(zlib SHARED IMPORTED)
	SET_PROPERTY(TARGET zlib PROPERTY IMPORTED_IMPLIB_DEBUG ${CMAKE_SOURCE_DIR}/thirdparty/gRPC/vsprojects/packages/grpc.dependencies.zlib.1.2.8.10/build/native/lib/v140/x64/Debug/dynamic/stdcall/zlib.lib)
	SET_PROPERTY(TARGET zlib PROPERTY IMPORTED_LOCATION_DEBUG  ${CMAKE_SOURCE_DIR}/thirdparty/gRPC/vsprojects/packages/grpc.dependencies.zlib.redist.1.2.8.10/build/native/bin/v140/x64/Debug/dynamic/stdcall/zlib.dll)
	SET_PROPERTY(TARGET zlib PROPERTY IMPORTED_IMPLIB_RELEASE ${CMAKE_SOURCE_DIR}/thirdparty/gRPC/vsprojects/packages/grpc.dependencies.zlib.1.2.8.10/build/native/lib/v140/x64/Release/dynamic/stdcall/zlib.lib)
	SET_PROPERTY(TARGET zlib PROPERTY IMPORTED_LOCATION_RELEASE  ${CMAKE_SOURCE_DIR}/thirdparty/gRPC/vsprojects/packages/grpc.dependencies.zlib.redist.1.2.8.10/build/native/bin/v140/x64/Release/dynamic/stdcall/zlib.dll)
	
	ADD_LIBRARY(Ws2_32 SHARED IMPORTED)
	SET_PROPERTY(TARGET Ws2_32 PROPERTY IMPORTED_IMPLIB ws2_32.lib)	
	
	EXECUTE_PROCESS(COMMAND  
        ${CMAKE_SOURCE_DIR}/thirdparty/gRPC/third_party/protobuf/cmake/win/Debug/protoc.exe 
        -I ${CMAKE_SOURCE_DIR}/protos/app 
        --grpc_out=${CMAKE_SOURCE_DIR}/client/src 
		--grpc_out=${CMAKE_SOURCE_DIR}/server/src
        --cpp_out=${CMAKE_SOURCE_DIR}/client/src 
	    --cpp_out=${CMAKE_SOURCE_DIR}/server/src 
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

	ADD_LIBRARY(PocoFoundation STATIC IMPORTED)
	ADD_LIBRARY(PocoUtil STATIC IMPORTED)
	ADD_LIBRARY(PocoXML STATIC IMPORTED)
	ADD_LIBRARY(PocoJSON STATIC IMPORTED)

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