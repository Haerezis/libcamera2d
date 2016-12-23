cmake_minimum_required(VERSION 3.0)
project(01_basics)

add_executable(
  ${PROJECT_NAME}
  ${01_basics_SOURCE_DIR}/main.cpp
  ${01_basics_SOURCE_DIR}/Player.cpp
  ${01_basics_SOURCE_DIR}/Player.hpp
  ${01_basics_SOURCE_DIR}/tilemap_data.hpp
)
target_link_libraries(${PROJECT_NAME} libsample)
