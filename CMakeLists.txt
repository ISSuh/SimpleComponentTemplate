CMAKE_MINIMUM_REQUIRED (VERSION 3.2)
PROJECT (SMT)

SET ( CMAKE_CXX_STANDARD 11)
SET ( CMAKE_CXX_STANDARD_REQUIRED ON)
ADD_COMPILE_OPTIONS ( -g -Wall )

if(${CMAKE_HOST_UNIX})
	if(${CMAKE_HOST_APPLE})
		message("APPLE")
		SET(CMAKE_SHARED_MODULE_CREATE_C_FLAGS "-flat_namespace -undefined suppress")
	else()
		message("LINUX")
	endif()
else()
	message("WIN")
endif()

#-------------------------------------------------------------------------------
# Linking option about debug, release
#-------------------------------------------------------------------------------
SET ( CMAKE_C_FLAGS_DEBUG "-DDEBUG -DC_FLAGS" )
SET ( CMAKE_EXE_LINKER_FLAGS_DEBUG "-DDEBUG -DLINKER_FLAGS" )
 
SET ( CMAKE_C_FLAGS_RELEASE "-DRELEASE -DC_FLAGS" )
SET ( CMAKE_EXE_LINKER_FLAGS_RELEASE "-DRELEASE -DLINKER_FLAGS" )

#-------------------------------------------------------------------------------
# third party Module
#-------------------------------------------------------------------------------
set(JSON_BuildTests OFF CACHE INTERNAL "")
add_subdirectory(third_party/json
				third_party/json
)

add_subdirectory(third_party/spdlog
				third_party/spdlog
)

link_directories( 
	build/third_party/spdlog
)

#-------------------------------------------------------------------------------
# Uer Module
#-------------------------------------------------------------------------------
add_subdirectory(example
				example
)

link_directories( 
	build/example/hello_world
)

#-------------------------------------------------------------------------------
# Project files
#-------------------------------------------------------------------------------
include_directories(
	${PROJECT_SOURCE_DIR}/include
	${PROJECT_SOURCE_DIR}/third_party/json/include
	${PROJECT_SOURCE_DIR}/third_party/spdlog/include

	${PROJECT_SOURCE_DIR}/third_party/boost/asio/include
	${PROJECT_SOURCE_DIR}/third_party/boost/dll/include
	${PROJECT_SOURCE_DIR}/third_party/boost/thread/include
)

file(GLOB SOURCE SOURCE
	${PROJECT_SOURCE_DIR}/src/node.cpp
)

#-------------------------------------------------------------------------------
#  node build
#-------------------------------------------------------------------------------
add_executable(smtNode ${SOURCE})

target_link_libraries(smtNode
PRIVATE
	nlohmann_json::nlohmann_json
	spdlog
)

set_property(TARGET smtNode PROPERTY FOLDER "build")