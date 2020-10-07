CMAKE_MINIMUM_REQUIRED (VERSION 3.2)
project(hello_world)

message("SimpleModule hello_world Example")

#-------------------------------------------------------------------------------
# Example Build
#-------------------------------------------------------------------------------
set(CMAKE_LIBRARY_OUTPUT_DIRECTORY ${BUILD_DIR_LIBRARY})

include_directories(
     ${SRPC_INCLUDES}
)

file(GLOB SOURCE
    hello_world_module.cpp
)

add_library(hello_world SHARED ${SOURCE})
target_link_libraries(hello_world ${BUILD_DIR_LIBRARY}/libsmt.so)

set_target_properties(hello_world PROPERTIES LINKER_LANGUAGE CXX)