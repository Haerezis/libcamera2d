cmake_minimum_required(VERSION 3.5)

set(
  HEADERS
  ${CMAKE_CURRENT_SOURCE_DIR}/include/libcamera2d/Camera.hpp
  ${CMAKE_CURRENT_SOURCE_DIR}/include/libcamera2d/Camera_positionLocking.hpp
  ${CMAKE_CURRENT_SOURCE_DIR}/include/libcamera2d/Object2D.hpp
  ${CMAKE_CURRENT_SOURCE_DIR}/include/libcamera2d/Object1D.hpp
  ${CMAKE_CURRENT_SOURCE_DIR}/include/libcamera2d/PositionLocking.hpp
)

set(
  SOURCES
  ${CMAKE_CURRENT_SOURCE_DIR}/src/Camera.cpp
  ${CMAKE_CURRENT_SOURCE_DIR}/src/Camera_positionLocking.cpp
  ${CMAKE_CURRENT_SOURCE_DIR}/src/Object2D.cpp
  ${CMAKE_CURRENT_SOURCE_DIR}/src/Object1D.cpp
  ${CMAKE_CURRENT_SOURCE_DIR}/src/PositionLocking.cpp
)

add_library(${CMAKE_PROJECT_NAME} ${HEADERS} ${SOURCES})
target_include_directories(
  ${CMAKE_PROJECT_NAME}
  PUBLIC
    ${CMAKE_CURRENT_SOURCE_DIR}/include
)
set_target_properties(${CMAKE_PROJECT_NAME} PROPERTIES PREFIX "")
