CMAKE_MINIMUM_REQUIRED (VERSION 3.7)
PROJECT (SMT)

SET ( CMAKE_C_COMPILER g++)
set ( CMAKE_CXX_STANDARD 11)
ADD_COMPILE_OPTIONS ( -g -Wall )

set ( CMAKE_PREFIX_PATH /usr/lib/x86_64-linux-gnu/cmake)

#-------------------------------------------------------------------------------
# Linking option about debug, release
#-------------------------------------------------------------------------------
SET ( CMAKE_C_FLAGS_DEBUG "-DDEBUG -DC_FLAGS" )
SET ( CMAKE_EXE_LINKER_FLAGS_DEBUG "-DDEBUG -DLINKER_FLAGS" )
 
SET ( CMAKE_C_FLAGS_RELEASE "-DRELEASE -DC_FLAGS" )
SET ( CMAKE_EXE_LINKER_FLAGS_RELEASE "-DRELEASE -DLINKER_FLAGS" )

#-------------------------------------------------------------------------------
# Third paty library
#-------------------------------------------------------------------------------


#-------------------------------------------------------------------------------
# Project files
#-------------------------------------------------------------------------------
include_directories(
	${PROJECT_SOURCE_DIR}/include
	${PROJECT_SOURCE_DIR}/include/3thParty
)

set(smtNode_SOURCE
	${PROJECT_SOURCE_DIR}/src/node.cpp
)

#-------------------------------------------------------------------------------
#  example build
#-------------------------------------------------------------------------------
add_executable(smtNode ${smtNode_SOURCE})
target_link_libraries(smtNode

)

set_property(TARGET smtNode PROPERTY FOLDER "build")