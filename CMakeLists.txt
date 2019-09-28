cmake_minimum_required(VERSION 3.13)

set(_PROJECT_MAJOR_VERSION 0)
set(_PROJECT_MINOR_VERSION 1)
set(_PROJECT_PATCH_VERSION 0)
set(_PROJECT_VERSION
  ${_PROJECT_MAJOR_VERSION}.${_PROJECT_MINOR_VERSION}.${_PROJECT_PATCH_VERSION})

project(cmake-best-practice LANGUAGES CXX VERSION "${_PROJECT_VERSION}")

# ############################################################### #
# library options ############################################### #
# ############################################################### #
option(library_BUILD_SHARED "Build the library as shared." OFF)
set(
    library_INSTALL_CMAKE_PREFIX 
    "lib/cmake/library" 
    CACHE PATH "Installation directory for CMake files")
set(
    library_INSTALL_INCLUDE_PREFIX 
    "include/library" 
    CACHE PATH "Installation directory for header files")
set(
    library_INSTALL_BIN_PREFIX 
    "bin" 
    CACHE PATH "Installation directory for executables")
set(
    library_INSTALL_LIB_PREFIX 
    "lib" 
    CACHE PATH "Installation directory for libraries")
    
# ############################################################### #
# headeronly options ############################################ #
# ############################################################### #
set(
    headeronly_INSTALL_CMAKE_PREFIX 
    "lib/cmake/headeronly"
    CACHE PATH "Installation directory for CMake files")
set(
    headeronly_INSTALL_INCLUDE_PREFIX 
    "include/headeronly" 
    CACHE PATH "Installation directory for header files")

# Cmake module path
set(CMAKE_MODULE_PATH ${CMAKE_MODULE_PATH} "${PROJECT_SOURCE_DIR}/cmake/modules")
set(PROJECT_ROOT_DIR ${CMAKE_CURRENT_SOURCE_DIR})

add_subdirectory(src/library)
add_subdirectory(include/headeronly)
add_subdirectory(src/executable)