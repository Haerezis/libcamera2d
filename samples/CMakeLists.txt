cmake_minimum_required(VERSION 3.0)
project(samples)

set(
  SAMPLES
  01_basics
  02_simplePlatformer
)

add_library(
  libsample
  ${samples_SOURCE_DIR}/SdlException.cpp
  ${samples_SOURCE_DIR}/SdlException.hpp
  ${samples_SOURCE_DIR}/Tilemap.cpp
  ${samples_SOURCE_DIR}/Tilemap.hpp
)
target_include_directories(libsample PUBLIC ${samples_SOURCE_DIR})
target_link_libraries(libsample ${CMAKE_PROJECT_NAME} libcamera2d)
set_target_properties(libsample PROPERTIES PREFIX "")

foreach (subdir ${SAMPLES})
  add_subdirectory(${subdir})
endforeach ()
