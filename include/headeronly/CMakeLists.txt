set(SUBPROJ_NAME "headeronly")
set(SUBPROJ_NAMESPACE "cmake-best-practice")

set(${SUBPROJ_NAME}_MAJOR_VERSION 0)
set(${SUBPROJ_NAME}_MINOR_VERSION 1)
set(${SUBPROJ_NAME}_PATCH_VERSION 0)
set(${SUBPROJ_NAME}_VERSION
    ${${SUBPROJ_NAME}_MAJOR_VERSION}.${${SUBPROJ_NAME}_MINOR_VERSION}.${${SUBPROJ_NAME}_PATCH_VERSION})

file(
    GLOB ${SUBPROJ_NAME}_HEADERS
    "*.h"
    "*.hxx"
    "*.hpp")

set(
    ${SUBPROJ_NAME}_SRC
    ${${SUBPROJ_NAME}_HEADERS})

add_library(
    ${SUBPROJ_NAME}
    INTERFACE)

target_compile_features(
    ${SUBPROJ_NAME}
    INTERFACE cxx_std_17)

target_include_directories(
    ${SUBPROJ_NAME}
    INTERFACE $<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}>
              $<INSTALL_INTERFACE:include>)

# Find yaml-cpp
find_package(yaml-cpp CONFIG REQUIRED)

# Set yaml-cpp as dependency
target_link_libraries(
    ${SUBPROJ_NAME}
    INTERFACE yaml-cpp)
    
# ############################################################### #
# Installing #################################################### #
# ############################################################### #

# Create export targets
install(
    TARGETS ${SUBPROJ_NAME}
    EXPORT  ${SUBPROJ_NAME}-targets)

# Install headers
install(
    FILES       ${${SUBPROJ_NAME}_HEADERS}
    DESTINATION ${${SUBPROJ_NAME}_INSTALL_INCLUDE_PREFIX})

set(${SUBPROJ_NAME}-targets_FILE "${SUBPROJ_NAME}-targets.cmake")

# Create config-targets cmake file
install(
    EXPORT      ${SUBPROJ_NAME}-targets
    FILE        ${${SUBPROJ_NAME}-targets_FILE}
    NAMESPACE   ${SUBPROJ_NAMESPACE}::
    DESTINATION ${${SUBPROJ_NAME}_INSTALL_CMAKE_PREFIX})

# Create config files
include(CMakePackageConfigHelpers)
write_basic_package_version_file(
    "${PROJECT_BINARY_DIR}/${SUBPROJ_NAME}-config-version.cmake"
    VERSION ${cmake-test-headeronly_VERSION}
    COMPATIBILITY AnyNewerVersion)

configure_package_config_file(
    "${PROJECT_ROOT_DIR}/cmake/${SUBPROJ_NAME}-config.cmake.in"
    "${PROJECT_BINARY_DIR}/${SUBPROJ_NAME}-config.cmake"
    INSTALL_DESTINATION ${${SUBPROJ_NAME}_INSTALL_CMAKE_PREFIX})

# Install config files
install(
    FILES
        "${PROJECT_BINARY_DIR}/${SUBPROJ_NAME}-config.cmake"
        "${PROJECT_BINARY_DIR}/${SUBPROJ_NAME}-config-version.cmake"
    DESTINATION ${${SUBPROJ_NAME}_INSTALL_CMAKE_PREFIX})