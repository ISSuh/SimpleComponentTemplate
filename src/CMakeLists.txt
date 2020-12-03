CMAKE_MINIMUM_REQUIRED (VERSION 3.2)
project(smt_library)

message("SMT Library build")

#-------------------------------------------------------------------------------
# Compile Option
#-------------------------------------------------------------------------------
SET (CMAKE_CXX_STANDARD 11)
SET (CMAKE_CXX_STANDARD_REQUIRED ON)
set (CMAKE_CXX_FLAGS "-g -Wall -fPIC -rdynamic -ldl -C")

#-------------------------------------------------------------------------------
# Linking option about debug, release
#-------------------------------------------------------------------------------
# SET(CMAKE_C_FLAGS_DEBUG "-DDEBUG -DC_FLAGS")
SET(CMAKE_EXE_LINKER_FLAGS_DEBUG "-DDEBUG -DLINKER_FLAGS")

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
  # loader/ModuleLoader.cpp
  loader/ModuleLoaderManager.cpp
  loader/ModuleLoaderUtil.cpp
  loader/ModuleOpener.cpp
)

SET(SMT_SOURCES_MODULE
  module/ModuleInfo.cpp
)

SET(SMT_SOURCES_UTIL
  util/JsonWrapper.cpp
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

set_target_properties(smt PROPERTIES
  LINKER_LANGUAGE CXX
)
