INCLUDE_DIRECTORIES(${CMAKE_CURRENT_SOURCE_DIR}/inc
					${CMAKE_SOURCE_DIR}/utils/inc
					${CMAKE_CURRENT_SOURCE_DIR}/src)
					
AUX_SOURCE_DIRECTORY(${CMAKE_CURRENT_SOURCE_DIR}/src DIR_SRCS)

FILE(GLOB INCS "inc/*.h")
FILE(GLOB HEADERS "src/*.h")
SOURCE_GROUP("Header Files" FILES ${INCS} ${HEADERS})

ADD_LIBRARY(dynamic SHARED ${DIR_SRCS} ${HEADERS} ${INCS})
TARGET_LINK_LIBRARIES(dynamic utils)
SET_TARGET_PROPERTIES(dynamic PROPERTIES FOLDER "Library")

IF(CMAKE_SYSTEM_NAME MATCHES "Windows") 
	ADD_DEFINITIONS(/D"Dynamic_EXPORTS")
	ADD_EXECUTABLE(dynamic_test "tests/dynamic_test.cxx")
	ADD_DEPENDENCIES(dynamic_test dynamic utils)
	TARGET_LINK_LIBRARIES(dynamic_test dynamic utils)
	SET_TARGET_PROPERTIES(dynamic_test PROPERTIES FOLDER "Library")
ELSE(CMAKE_SYSTEM_NAME MATCHES "Linux")
	ADD_EXECUTABLE(dynamic_test "tests/dynamic_test.cxx")
	ADD_DEPENDENCIES(dynamic_test dynamic utils)
	TARGET_LINK_LIBRARIES(dynamic_test dynamic utils)
	SET_TARGET_PROPERTIES(dynamic_test PROPERTIES FOLDER "Library")
ENDIF(CMAKE_SYSTEM_NAME MATCHES "Windows")	
