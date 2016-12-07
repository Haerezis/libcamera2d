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

#For every subdirectory, we add an executable named after the directory name.
#This executable is linked to libscrollingcamera and SDL.
SUBDIRLIST(SUBDIRS ${CMAKE_CURRENT_SOURCE_DIR})
FOREACH(subdir ${SUBDIRS})
  add_subdirectory(${subdir})
ENDFOREACH()
