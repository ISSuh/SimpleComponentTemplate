CMAKE_MINIMUM_REQUIRED (VERSION 3.2)
PROJECT (SMT)

SET ( CMAKE_CXX_COMPILER g++)
SET ( CMAKE_CXX_STANDARD 11)
ADD_COMPILE_OPTIONS ( -g -Wall )

SET ( CMAKE_PREFIX_PATH /usr/lib/x86_64-linux-gnu/cmake)

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
# Uer Module
#-------------------------------------------------------------------------------
add_subdirectory(example/hello_world
				hello_world
)

#-------------------------------------------------------------------------------
# Project files
#-------------------------------------------------------------------------------
include_directories(
	${PROJECT_SOURCE_DIR}/include
	${PROJECT_SOURCE_DIR}/include/3thParty
)

SET(smtNode_SOURCE
	${PROJECT_SOURCE_DIR}/src/node.cpp
)

#-------------------------------------------------------------------------------
#  node build
#-------------------------------------------------------------------------------
add_executable(smtNode ${smtNode_SOURCE})
target_link_libraries(smtNode
	
)

set_property(TARGET smtNode PROPERTY FOLDER "build")