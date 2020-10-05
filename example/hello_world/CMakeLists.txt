CMAKE_MINIMUM_REQUIRED (VERSION 3.2)
project(hello_world)

include_directories(
    ../../include
    ../../include/3thParty
)

file(GLOB SOURCE 
    hello_world_module.cpp
)

add_library(hello_world SHARED ${SOURCE})

set_target_properties(hello_world PROPERTIES LINKER_LANGUAGE CXX)