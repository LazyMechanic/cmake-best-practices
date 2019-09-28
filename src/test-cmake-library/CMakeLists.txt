set(test-cmake-library_MAJOR_VERSION 0)
set(test-cmake-library_MINOR_VERSION 1)
set(test-cmake-library_PATCH_VERSION 0)
set(test-cmake-library_VERSION
    ${test-cmake-library_MAJOR_VERSION}.${test-cmake-library_MINOR_VERSION}.${test-cmake-library_PATCH_VERSION})

# Set build type to library target
if(test-cmake-library_BUILD_SHARED AND ${test-cmake-library_BUILD_SHARED} STREQUAL "ON")
    set(test-cmake-library_TARGET_TYPE "SHARED")
else()
    set(test-cmake-library_TARGET_TYPE "STATIC")
endif()

string(TOLOWER ${test-cmake-library_TARGET_TYPE} test-cmake-library_TARGET_TYPE_LOWER)

file(
    GLOB test-cmake-library_HEADERS
    "*.h"
    "*.hxx"
    "*.hpp")

file(
    GLOB test-cmake-library_SOURCES
    "*.c"
    "*.cc"
    "*.cxx"
    "*.cpp")

set(
    test-cmake-library_SRC
    ${test-cmake-library_HEADERS}
    ${test-cmake-library_SOURCES})

add_library(
    test-cmake-library 
    ${test-cmake-library_TARGET_TYPE} 
    ${test-cmake-library_SRC})

target_compile_features(
    test-cmake-library
    INTERFACE cxx_std_17)

set_target_properties(
    test-cmake-library PROPERTIES
    RUNTIME_OUTPUT_DIRECTORY "${PROJECT_BINARY_DIR}/bin"
    ARCHIVE_OUTPUT_DIRECTORY "${PROJECT_BINARY_DIR}/lib"
    LIBRARY_OUTPUT_DIRECTORY "${PROJECT_BINARY_DIR}/lib"
    OUTPUT_NAME              "test-cmake-library$<$<CONFIG:Debug>:d>")

target_include_directories(
    test-cmake-library
    PRIVATE   $<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}>
    INTERFACE $<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}>
              $<INSTALL_INTERFACE:include>)

# Find yaml-cpp
find_package(yaml-cpp CONFIG REQUIRED)

# Set yaml-cpp as dependency
target_link_libraries(
    test-cmake-library 
    yaml-cpp)
    
# ############################################################### #
# Installing #################################################### #
# ############################################################### #

# Create export targets
install(
    TARGETS test-cmake-library
    EXPORT  test-cmake-library-targets)

# Install headers
install(
    FILES ${test-cmake-library_HEADERS}
    DESTINATION ${test-cmake-library_INSTALL_INCLUDE_PREFIX})

# Set out paths
install(
    TARGETS test-cmake-library
    RUNTIME DESTINATION  ${test-cmake-library_INSTALL_BIN_PREFIX}
    ARCHIVE DESTINATION  ${test-cmake-library_INSTALL_LIB_PREFIX}
    LIBRARY DESTINATION  ${test-cmake-library_INSTALL_LIB_PREFIX})

set(test-cmake-library-targets_FILE "test-cmake-library-${test-cmake-library_TARGET_TYPE_LOWER}-targets.cmake")

# Create config-targets cmake file
install(
    EXPORT      test-cmake-library-targets
    FILE        ${test-cmake-library-targets_FILE}
    NAMESPACE   test-cmake::
    DESTINATION ${test-cmake-library_INSTALL_CMAKE_PREFIX})

# Create config files
include(CMakePackageConfigHelpers)
write_basic_package_version_file(
    "${PROJECT_BINARY_DIR}/test-cmake-library-config-version.cmake"
    VERSION ${cmake-test-library_VERSION}
    COMPATIBILITY AnyNewerVersion)

configure_package_config_file(
    "${test-cmake_ROOT_DIR}/cmake/test-cmake-library-config.cmake.in"
    "${PROJECT_BINARY_DIR}/test-cmake-library-config.cmake"
    INSTALL_DESTINATION ${test-cmake-library_INSTALL_CMAKE_PREFIX})

# Install config files
install(
    FILES
        "${PROJECT_BINARY_DIR}/test-cmake-library-config.cmake"
        "${PROJECT_BINARY_DIR}/test-cmake-library-config-version.cmake"
    DESTINATION ${test-cmake-library_INSTALL_CMAKE_PREFIX})