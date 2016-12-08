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

set(SRC_FILES "")
set(HEADER_FILES "")

file(GLOB FILES "${CMAKE_CURRENT_SOURCE_DIR}/*.cpp")
list(APPEND SRC_FILES ${FILES})

file(GLOB FILES "${CMAKE_CURRENT_SOURCE_DIR}/*.hpp")
list(APPEND HEADER_FILES ${FILES})
file(GLOB FILES "${CMAKE_CURRENT_SOURCE_DIR}/*.tpl")
list(APPEND HEADER_FILES ${FILES})

include_directories(${CMAKE_CURRENT_SOURCE_DIR})

#For every subdirectory, we add an executable named after the directory name.
#This executable is linked to libscrollingcamera and SDL.
SUBDIRLIST(SUBDIRS ${CMAKE_CURRENT_SOURCE_DIR})
FOREACH(subdir ${SUBDIRS})
  add_subdirectory(${subdir})
ENDFOREACH()
