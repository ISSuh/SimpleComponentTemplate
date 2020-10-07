CMAKE_MINIMUM_REQUIRED (VERSION 3.2)
project(smt)

message("SMT Library build")

#-------------------------------------------------------------------------------
# Library Build
#-------------------------------------------------------------------------------
set(CMAKE_LIBRARY_OUTPUT_DIRECTORY ${BUILD_DIR_LIBRARY})

SET(SMT_SOURCES_BASE

)

SET(SMT_SOURCES_CONTROLLER
  controller/ModuleController.cpp
)

SET(SMT_SOURCES_LOADER
  loader/ModuleLoader.cpp
  loader/ModuleLoaderManager.cpp
  loader/ModuleLoaderUtil.cpp
)

SET(SMT_SOURCES_MODULE
)

SET(SMT_SOURCES_UTIL
)

SET(SMT_SOURCES
  ${SMT_SOURCES_BASE}
  ${SMT_SOURCES_CONTROLLER}
  ${SMT_SOURCES_LOADER}
  ${SMT_SOURCES_MODULE}
  ${SMT_SOURCES_UTIL}
)

add_library(smt SHARED ${SMT_SOURCES})

target_include_directories(smt
  PUBLIC
    ${SMT_INCLUDES}
)

set_target_properties(smt PROPERTIES LINKER_LANGUAGE CXX)

#-------------------------------------------------------------------------------
#  Node build
#-------------------------------------------------------------------------------
add_subdirectory(launcher)
