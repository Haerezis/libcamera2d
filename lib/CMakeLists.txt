cmake_minimum_required(VERSION 3.5)

set(
  HEADERS
  ${CMAKE_CURRENT_SOURCE_DIR}/include/libcamera2d/Camera.hpp
  ${CMAKE_CURRENT_SOURCE_DIR}/include/libcamera2d/Camera_positionLocking.hpp
  ${CMAKE_CURRENT_SOURCE_DIR}/include/libcamera2d/libcamera2d.hpp
  ${CMAKE_CURRENT_SOURCE_DIR}/include/libcamera2d/Object2D.hpp
  ${CMAKE_CURRENT_SOURCE_DIR}/include/libcamera2d/ObjectDimension.hpp
  ${CMAKE_CURRENT_SOURCE_DIR}/include/libcamera2d/ObjectDimensionGenerator.hpp
  ${CMAKE_CURRENT_SOURCE_DIR}/include/libcamera2d/PositionLocking.hpp
  ${CMAKE_CURRENT_SOURCE_DIR}/include/libcamera2d/Offset.hpp
)

set(
  SOURCES
  ${CMAKE_CURRENT_SOURCE_DIR}/src/Camera.cpp
  ${CMAKE_CURRENT_SOURCE_DIR}/src/Camera_positionLocking.cpp
  ${CMAKE_CURRENT_SOURCE_DIR}/src/libcamera2d.cpp
  ${CMAKE_CURRENT_SOURCE_DIR}/src/Object2D.cpp
  ${CMAKE_CURRENT_SOURCE_DIR}/src/ObjectDimension.cpp
  ${CMAKE_CURRENT_SOURCE_DIR}/src/ObjectDimensionGenerator.cpp
  ${CMAKE_CURRENT_SOURCE_DIR}/src/PositionLocking.cpp
  ${CMAKE_CURRENT_SOURCE_DIR}/src/Offset.cpp
)

add_library(${CMAKE_PROJECT_NAME} ${HEADERS} ${SOURCES})
target_include_directories(
  ${CMAKE_PROJECT_NAME}
  PUBLIC
    ${CMAKE_CURRENT_SOURCE_DIR}/include
)
set_target_properties(${CMAKE_PROJECT_NAME} PROPERTIES PREFIX "")
