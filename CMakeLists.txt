cmake_minimum_required(VERSION 3.0)
project(libcamera2d)

set(CMAKE_MODULE_PATH ${CMAKE_MODULE_PATH} "${CMAKE_SOURCE_DIR}/cmake/")

find_package(SDL2 REQUIRED)

# setup version numbers
set(VERSION_MAJOR 0)
set(VERSION_MINOR 2)
set(VERSION_PATCH 0)


if (CMAKE_CXX_COMPILER_ID MATCHES "GNU" OR CMAKE_CXX_COMPILER_ID MATCHES "Clang")
  add_definitions("-std=c++11")
  add_definitions("-Wall -Wextra")
endif ()


set(INTERNAL_LIBS "")
set(EXTERNAL_LIBS "")
set(DEFINES "")
set(WARNING "")
set(FLAGS "")
set(CMAKE_CXX_FLAGS "${DEFINES} ${WARNING} ${FLAGS}")


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

# libcamera2d
set(
  HEADERS
  ${CMAKE_SOURCE_DIR}/include/libcamera2d/Camera.hpp
  ${CMAKE_SOURCE_DIR}/include/libcamera2d/Camera_staticOffsetFromTarget.hpp
  ${CMAKE_SOURCE_DIR}/include/libcamera2d/libcamera2d.hpp
  ${CMAKE_SOURCE_DIR}/include/libcamera2d/Object2d.hpp
)

set(
  SOURCES
  ${CMAKE_SOURCE_DIR}/src/Camera.cpp
  ${CMAKE_SOURCE_DIR}/src/Camera_staticOffsetFromTarget.cpp
  ${CMAKE_SOURCE_DIR}/src/libcamera2d.cpp
  ${CMAKE_SOURCE_DIR}/src/Object2d.cpp
)

add_library(${CMAKE_PROJECT_NAME} ${HEADERS} ${SOURCES})
target_include_directories(
  ${CMAKE_PROJECT_NAME}
  PUBLIC
    ${SDL2_INCLUDE_DIR}
    ${CMAKE_SOURCE_DIR}/include
)
target_link_libraries(${CMAKE_PROJECT_NAME} ${SDL2_LIBRARY})
set_target_properties(${CMAKE_PROJECT_NAME} PROPERTIES PREFIX "")

# Optional samples
if(${BUILD_SAMPLES})
  add_subdirectory(samples)
endif()

