CMAKE_MINIMUM_REQUIRED (VERSION 3.2)
PROJECT (SMT)

#-------------------------------------------------------------------------------
# Compile Option
#-------------------------------------------------------------------------------
SET (CMAKE_CXX_STANDARD 11)
SET (CMAKE_CXX_STANDARD_REQUIRED ON)
ADD_COMPILE_OPTIONS (-g -Wall)

#-------------------------------------------------------------------------------
# Linking option about debug, release
#-------------------------------------------------------------------------------
SET (CMAKE_C_FLAGS_DEBUG "-DDEBUG -DC_FLAGS")
SET (CMAKE_EXE_LINKER_FLAGS_DEBUG "-DDEBUG -DLINKER_FLAGS")

#-------------------------------------------------------------------------------
# Build Setting
#-------------------------------------------------------------------------------
SET(PROJECT_DIR ${PROJECT_SOURCE_DIR})

SET(BUILD_DIR ${CMAKE_SOURCE_DIR}/build)
SET(BUILD_DIR_RUNTIME ${BUILD_DIR}/bin)
SET(BUILD_DIR_LIBRARY ${BUILD_DIR}/lib)

include_directories(
	${PROJECT_SOURCE_DIR}/include
	${PROJECT_SOURCE_DIR}/third_party/json/include
	${PROJECT_SOURCE_DIR}/third_party/spdlog/include

	${PROJECT_SOURCE_DIR}/third_party/boost/asio/include
	${PROJECT_SOURCE_DIR}/third_party/boost/dll/include
	${PROJECT_SOURCE_DIR}/third_party/boost/thread/include
)

file(GLOB SOURCE SOURCE
	${PROJECT_SOURCE_DIR}/src/launcher/node.cpp
)

SET(SMT_INCLUDES
    ${PROJECT_DIR}/include
)

#-------------------------------------------------------------------------------
#  SMT Build
#-------------------------------------------------------------------------------
add_subdirectory(src)

#-------------------------------------------------------------------------------
# User Module example
#-------------------------------------------------------------------------------
add_subdirectory(example)

