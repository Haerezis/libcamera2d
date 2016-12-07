cmake_minimum_required (VERSION 3.0)

# project name
get_filename_component(PROJECT_NAME ${CMAKE_CURRENT_SOURCE_DIR} NAME)
project (${PROJECT_NAME})

set(INCLUDE_ROOT "${CMAKE_CURRENT_SOURCE_DIR}")
set(SRC_ROOT "${CMAKE_CURRENT_SOURCE_DIR}")

file(GLOB SRC_FILES "${SRC_ROOT}/*.cpp")
file(GLOB_RECURSE HEADER_FILES "${INCLUDE_ROOT}/*.hpp")

find_package(SDL2 REQUIRED)

add_executable(${PROJECT_NAME} ${SRC_FILES} ${HEADER_FILES})
target_include_directories(${PROJECT_NAME} PUBLIC ${INCLUDE_ROOT})
target_include_directories(${PROJECT_NAME} PUBLIC ${SDL2_INCLUDE_DIR})
target_link_libraries(${PROJECT_NAME} libcamera2d)
target_link_libraries(${PROJECT_NAME} ${SDL2_LIBRARY})