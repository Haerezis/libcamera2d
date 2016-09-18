cmake_minimum_required (VERSION 3.0)

#Macro listing subdirectories of a directory.
MACRO(SUBDIRLIST result curdir)
  FILE(GLOB children RELATIVE ${curdir} ${curdir}/*)
  SET(dirlist "")
  FOREACH(child ${children})
    IF(IS_DIRECTORY ${curdir}/${child})
      LIST(APPEND dirlist ${child})
    ENDIF()
  ENDFOREACH()
  SET(${result} ${dirlist})
ENDMACRO()

find_library(SDL2 REQUIRED)

#For every subdirectory, we add an executable named after the directory name.
#This executable is linked to libscrollingcamera and SDL.
SUBDIRLIST(SUBDIRS ${CMAKE_CURRENT_SOURCE_DIR})
FOREACH(subdir ${SUBDIRS})
  set(SampleName ${subdir})
  set(INCLUDE_ROOT "${subdir}")
  set(SRC_ROOT "${subdir}")

  file(GLOB SRC_FILES "${SRC_ROOT}/*.cpp")
  file(GLOB_RECURSE HEADER_FILES "${INCLUDE_ROOT}/*.hpp")

  add_executable(${SampleName} ${SRC_FILES} ${HEADER_FILES})
  target_include_directories(${SampleName} PUBLIC ${INCLUDE_ROOT})
  target_link_libraries(${SampleName} ${PROJECT_NAME})
  target_link_libraries(${SampleName} ${SDL2_LIBRARY})
ENDFOREACH()
