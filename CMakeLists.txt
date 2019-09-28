cmake_minimum_required(VERSION 3.13)

set(_PROJECT_MAJOR_VERSION 0)
set(_PROJECT_MINOR_VERSION 1)
set(_PROJECT_PATCH_VERSION 0)
set(_PROJECT_VERSION
  ${_PROJECT_MAJOR_VERSION}.${_PROJECT_MINOR_VERSION}.${_PROJECT_PATCH_VERSION})

project(test-cmake LANGUAGES CXX VERSION "${_PROJECT_VERSION}")

# ############################################################### #
# test-cmake-library options #################################### #
# ############################################################### #
option(test-cmake-library_BUILD_SHARED "Build the library as shared." OFF)
set(
    test-cmake-library_INSTALL_CMAKE_PREFIX 
    "lib/cmake/test-cmake-library" 
    CACHE PATH "Installation directory for CMake files")
set(
    test-cmake-library_INSTALL_INCLUDE_PREFIX 
    "include/test-cmake-headeronly" 
    CACHE PATH "Installation directory for header files")
set(
    test-cmake-library_INSTALL_BIN_PREFIX 
    "bin" 
    CACHE PATH "Installation directory for executables")
set(
    test-cmake-library_INSTALL_LIB_PREFIX 
    "lib" 
    CACHE PATH "Installation directory for libraries")
    
# ############################################################### #
# test-cmake-headeronly options ################################# #
# ############################################################### #
set(
    test-cmake-headeronly_INSTALL_CMAKE_PREFIX 
    "lib/cmake/test-cmake-headeronly"
    CACHE PATH "Installation directory for CMake files")
set(
    test-cmake-headeronly_INSTALL_INCLUDE_PREFIX 
    "include/test-cmake-headeronly" 
    CACHE PATH "Installation directory for header files")

# Cmake module path
set(CMAKE_MODULE_PATH ${CMAKE_MODULE_PATH} "${PROJECT_SOURCE_DIR}/cmake/modules")
set(test-cmake_ROOT_DIR ${CMAKE_CURRENT_SOURCE_DIR})

add_subdirectory(src/test-cmake-library)
add_subdirectory(include/test-cmake-headeronly)
add_subdirectory(src/test-cmake-executable)