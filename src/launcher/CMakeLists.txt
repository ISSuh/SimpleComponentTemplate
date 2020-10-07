CMAKE_MINIMUM_REQUIRED (VERSION 3.2)
project(smt)

message("SMT Launcher build")

#-------------------------------------------------------------------------------
#  Node build
#-------------------------------------------------------------------------------
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY  ${BUILD_DIR_RUNTIME} )

SET(SMT_SOURCES_NODE
  Node.cpp
)

add_executable(smtNode ${SMT_SOURCES_NODE})

target_include_directories(smtNode PUBLIC ${SMT_INCLUDES})
target_link_libraries(smtNode ${BUILD_DIR_LIBRARY}/libsmt.so)