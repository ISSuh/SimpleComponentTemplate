CMAKE_MINIMUM_REQUIRED (VERSION 3.2)
project(smt_launcher)

message("SMT Launcher build")

#-------------------------------------------------------------------------------
# Compile Option
#-------------------------------------------------------------------------------
set(CMAKE_CXX_COMPILER "/usr/bin/g++")
SET (CMAKE_CXX_STANDARD 11)
SET (CMAKE_CXX_STANDARD_REQUIRED ON)
# set (CMAKE_CXX_FLAGS "-g -Wall -fPIC -rdynamic -shared -ldl -C")
set (CMAKE_CXX_FLAGS "-g -Wall -fPIC -rdynamic -ldl -C")

#-------------------------------------------------------------------------------
# Linking option about debug, release
#-------------------------------------------------------------------------------
SET(CMAKE_EXE_LINKER_FLAGS_DEBUG "-DDEBUG -DLINKER_FLAGS")

#-------------------------------------------------------------------------------
#  Node build
#-------------------------------------------------------------------------------
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY  ${BUILD_DIR_RUNTIME})

include_directories(
  ${SMT_INCLUDES}
)

link_directories(
  ${BUILD_DIR_LIBRARY}
)

SET(SMT_SOURCES_NODE
  Node.cpp
)

add_executable(smtNode Node.cpp)
target_include_directories(smtNode PUBLIC ${SMT_INCLUDES})
target_link_libraries(smtNode PUBLIC smt ${CMAKE_DL_LIBS})
