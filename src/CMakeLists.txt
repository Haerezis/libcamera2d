cmake_minimum_required (VERSION 3.0)

set(INCLUDE_ROOT "${PROJECT_SOURCE_DIR}/include/")
set(SRC_ROOT "${PROJECT_SOURCE_DIR}/src/")

file(GLOB SRC_FILES "${SRC_ROOT}/*.cpp")
file(GLOB_RECURSE HEADER_FILES "${INCLUDE_ROOT}/*.hpp")

add_library(${PROJECT_NAME} ${SRC_FILES} ${HEADER_FILES})

target_include_directories(${PROJECT_NAME} PUBLIC ${INCLUDE_ROOT})
