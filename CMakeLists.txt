CMAKE_MINIMUM_REQUIRED (VERSION 3.2)
PROJECT (SMT)

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

SET(SMT_INCLUDES
    ${PROJECT_DIR}/include
)

#-------------------------------------------------------------------------------
#  SMT Build
#-------------------------------------------------------------------------------
add_subdirectory(src)

#-------------------------------------------------------------------------------
#  SMT Launcher Build
#-------------------------------------------------------------------------------
add_subdirectory(launcher)

#-------------------------------------------------------------------------------
# User Module example
#-------------------------------------------------------------------------------
add_subdirectory(example)
