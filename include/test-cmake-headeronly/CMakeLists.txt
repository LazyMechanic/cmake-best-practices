set(test-cmake-headeronly_MAJOR_VERSION 0)
set(test-cmake-headeronly_MINOR_VERSION 1)
set(test-cmake-headeronly_PATCH_VERSION 0)
set(test-cmake-headeronly_VERSION
    ${test-cmake-headeronly_MAJOR_VERSION}.${test-cmake-headeronly_MINOR_VERSION}.${test-cmake-headeronly_PATCH_VERSION})

file(
    GLOB test-cmake-headeronly_HEADERS
    "*.h"
    "*.hxx"
    "*.hpp")

set(
    test-cmake-headeronly_SRC
    ${test-cmake-headeronly_HEADERS})

add_library(
    test-cmake-headeronly
    INTERFACE)

target_compile_features(
    test-cmake-headeronly
    INTERFACE cxx_std_17)

target_include_directories(
    test-cmake-headeronly
    INTERFACE $<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}>
              $<INSTALL_INTERFACE:include>)

# Find yaml-cpp
find_package(yaml-cpp CONFIG REQUIRED)

# Set yaml-cpp as dependency
target_link_libraries(
    test-cmake-headeronly
    INTERFACE yaml-cpp)
    
# ############################################################### #
# Installing #################################################### #
# ############################################################### #

# Create export targets
install(
    TARGETS test-cmake-headeronly
    EXPORT  test-cmake-headeronly-targets)

# Install headers
install(
    FILES       ${test-cmake-headeronly_HEADERS}
    DESTINATION ${test-cmake-headeronly_INSTALL_INCLUDE_PREFIX})

set(test-cmake-headeronly-targets_FILE "test-cmake-headeronly-targets.cmake")

# Create config-targets cmake file
install(
    EXPORT      test-cmake-headeronly-targets
    FILE        ${test-cmake-headeronly-targets_FILE}
    NAMESPACE   test-cmake::
    DESTINATION ${test-cmake-headeronly_INSTALL_CMAKE_PREFIX})

# Create config files
include(CMakePackageConfigHelpers)
write_basic_package_version_file(
    "${PROJECT_BINARY_DIR}/test-cmake-headeronly-config-version.cmake"
    VERSION ${cmake-test-headeronly_VERSION}
    COMPATIBILITY AnyNewerVersion)

configure_package_config_file(
    "${test-cmake_ROOT_DIR}/cmake/test-cmake-headeronly-config.cmake.in"
    "${PROJECT_BINARY_DIR}/test-cmake-headeronly-config.cmake"
    INSTALL_DESTINATION ${test-cmake-headeronly_INSTALL_CMAKE_PREFIX})

# Install config files
install(
    FILES
        "${PROJECT_BINARY_DIR}/test-cmake-headeronly-config.cmake"
        "${PROJECT_BINARY_DIR}/test-cmake-headeronly-config-version.cmake"
    DESTINATION ${test-cmake-headeronly_INSTALL_CMAKE_PREFIX})