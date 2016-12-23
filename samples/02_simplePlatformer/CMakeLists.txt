cmake_minimum_required(VERSION 3.0)
project(02_simplePlatformer)

add_executable(
  ${PROJECT_NAME}
  ${02_simplePlatformer_SOURCE_DIR}/main.cpp
  ${02_simplePlatformer_SOURCE_DIR}/Player.cpp
  ${02_simplePlatformer_SOURCE_DIR}/Player.hpp
  ${02_simplePlatformer_SOURCE_DIR}/tilemap_data.hpp
)
target_link_libraries(${PROJECT_NAME} libsample)
