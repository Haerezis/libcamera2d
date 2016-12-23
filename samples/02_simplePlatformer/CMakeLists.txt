cmake_minimum_required(VERSION 3.0)
get_filename_component(PROJECT_NAME ${CMAKE_CURRENT_SOURCE_DIR} NAME) 
project(${PROJECT_NAME})

add_executable(
  ${PROJECT_NAME}
  ${PROJECT_SOURCE_DIR}/main.cpp
  ${PROJECT_SOURCE_DIR}/Player.cpp
  ${PROJECT_SOURCE_DIR}/Player.hpp
  ${PROJECT_SOURCE_DIR}/tilemap_data.hpp
)
target_link_libraries(${PROJECT_NAME} libsample)
