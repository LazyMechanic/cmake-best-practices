set(SUBPROJ_NAME                          "headeronly")
set(${SUBPROJ_NAME}_NAMESPACE             "cmake-best-practices")

set(${SUBPROJ_NAME}_CXX_STANDARD          17)
set(${SUBPROJ_NAME}_CXX_EXTENSIONS        OFF)
set(${SUBPROJ_NAME}_CXX_STANDARD_REQUIRED YES)

set(${SUBPROJ_NAME}_MAJOR_VERSION         0)
set(${SUBPROJ_NAME}_MINOR_VERSION         1)
set(${SUBPROJ_NAME}_PATCH_VERSION         0)

# ############################################################### #
# Options ####################################################### #
# ############################################################### #

include(OptionHelpers)
generate_basic_options_headeronly(${SUBPROJ_NAME})

# Insert here your specififc options for build:
# .............................................

# ############################################################### #
# Library version ############################################### #
# ############################################################### #

set(${SUBPROJ_NAME}_VERSION
    ${${SUBPROJ_NAME}_MAJOR_VERSION}.${${SUBPROJ_NAME}_MINOR_VERSION}.${${SUBPROJ_NAME}_PATCH_VERSION})

# ############################################################### #
# Set all target sources ######################################## #
# ############################################################### #

# Include file with all source and header files
include(${SUBPROJ_NAME}Files)

set(
    ${SUBPROJ_NAME}_HEADERS
    ${HEADERS})

# Unset temp variable
unset(HEADERS)

set(
    ${SUBPROJ_NAME}_ALL_SRCS
    ${${SUBPROJ_NAME}_HEADERS})

# ############################################################### #
# Create target for build ####################################### #
# ############################################################### #

# Interface library target
add_library(
    ${SUBPROJ_NAME}
    INTERFACE)

# Enable C++ standard on this project
set_target_properties(
    ${SUBPROJ_NAME} PROPERTIES 
    INTERFACE_CXX_STANDARD          ${${SUBPROJ_NAME}_CXX_STANDARD}
    INTERFACE_CXX_EXTENSIONS        ${${SUBPROJ_NAME}_CXX_EXTENSIONS}
    INTERFACE_CXX_STANDARD_REQUIRED ${${SUBPROJ_NAME}_CXX_STANDARD_REQUIRED})

target_include_directories(
    ${SUBPROJ_NAME}
    INTERFACE $<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}>
              $<INSTALL_INTERFACE:include>)
    
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

set(SUBPROJ_TARGETS_FILE "${SUBPROJ_NAME}-targets.cmake")

# Create config-targets cmake file
install(
    EXPORT      ${SUBPROJ_NAME}-targets
    FILE        ${SUBPROJ_TARGETS_FILE}
    NAMESPACE   ${${SUBPROJ_NAME}_NAMESPACE}::
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