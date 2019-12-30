CMAKE_MINIMUM_REQUIRED (VERSION 3.2)
project(hello_world)

include_directories(
    ../../include
    ../../include/3thParty
)

file(GLOB SOURCE 
    hello_world.hpp
)

add_library(hello_world SHARED 
    ${SOURCE}
)