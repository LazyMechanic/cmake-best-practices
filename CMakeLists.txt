cmake_minimum_required(VERSION 3.13)

# Cmake module path
set(PROJECT_ROOT_DIR ${CMAKE_CURRENT_SOURCE_DIR})
set(CMAKE_MODULE_PATH ${CMAKE_MODULE_PATH} "${PROJECT_ROOT_DIR}/cmake/modules")

include(ProjectConfig)

set(_PROJECT_VERSION
  ${_PROJECT_MAJOR_VERSION}.${_PROJECT_MINOR_VERSION}.${_PROJECT_PATCH_VERSION})

project(${_PROJECT_NAME} LANGUAGES CXX VERSION ${_PROJECT_VERSION})

foreach(SUBPROJ ${SUBROJECT_LIST}) 
    add_subdirectory(${SUBPROJ})
endforeach()