cmake_minimum_required(VERSION 3.0)
project(libcamera2d)

set(CMAKE_MODULE_PATH ${CMAKE_MODULE_PATH} "${CMAKE_SOURCE_DIR}/cmake/")

find_package(SDL2 REQUIRED)

# setup version numbers
set(VERSION_MAJOR 0)
set(VERSION_MINOR 2)
set(VERSION_PATCH 0)


if (CMAKE_CXX_COMPILER_ID MATCHES "GNU" OR CMAKE_CXX_COMPILER_ID MATCHES "Clang")
  set(CMAKE_CXX_FLAGS "-std=c++11 -Wall -Wextra ${CMAKE_CXX_FLAGS}")
endif ()

set(OUTPUT_DIR "${CMAKE_CURRENT_SOURCE_DIR}/bin/")

set(CMAKE_LIBRARY_OUTPUT_DIRECTORY ${OUTPUT_DIR})
set(CMAKE_ARCHIVE_OUTPUT_DIRECTORY ${OUTPUT_DIR})
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${OUTPUT_DIR})
set(LIB_INSTALL_DIR ${OUTPUT_DIR})
# Second, for multi-config builds (e.g. msvc)
foreach( OUTPUTCONFIG ${CMAKE_CONFIGURATION_TYPES} )
  string( TOUPPER ${OUTPUTCONFIG} OUTPUTCONFIG )
  set( CMAKE_RUNTIME_OUTPUT_DIRECTORY_${OUTPUTCONFIG} ${OUTPUT_DIR} )
  set( CMAKE_LIBRARY_OUTPUT_DIRECTORY_${OUTPUTCONFIG} ${OUTPUT_DIR} )
  set( CMAKE_ARCHIVE_OUTPUT_DIRECTORY_${OUTPUTCONFIG} ${OUTPUT_DIR} )
endforeach( OUTPUTCONFIG CMAKE_CONFIGURATION_TYPES )

option(BUILD_DOC "build the documentation (doxygen is require)")
option(BUILD_SAMPLES "build the samples" ON)

add_subdirectory(lib)

# Optional samples
if(${BUILD_SAMPLES})
  add_subdirectory(samples)
endif()

