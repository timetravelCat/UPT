# Copyright 2024 timetravelCat
#
# Licensed under the Apache License, Version 2.0 (the "License");
# you may not use this file except in compliance with the License.
# You may obtain a copy of the License at
#
# https://www.apache.org/licenses/LICENSE-2.0
#
# Unless required by applicable law or agreed to in writing, software
# distributed under the License is distributed on an "AS IS" BASIS,
# WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
# See the License for the specific language governing permissions and
# limitations under the License.

cmake_minimum_required(VERSION 3.18)

# Include cmake module path
list(APPEND CMAKE_MODULE_PATH "${CMAKE_CURRENT_SOURCE_DIR}/cmake")

include(FindPackageHandleStandardArgs)
include(CMakeDependentOption)
include(CheckSymbolExists)
include(CheckLibraryExists)
include(ExternalProject)

project(ExampleProject VERSION 0.0.1 LANGUAGES C CXX)
set(CMAKE_EXPORT_COMPILE_COMMANDS ON)

# Set the C++ standard
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

# Set the default build type to 'Release' if not specified
if(NOT CMAKE_BUILD_TYPE)
    set(CMAKE_BUILD_TYPE Release CACHE STRING "Choose the type of build (Debug, Release, RelWithDebInfo, MinSizeRel)" FORCE)
endif()

# Set the default library type to 'SHARED' if not specified
if(NOT DEFINED BUILD_SHARED_LIBS)
    set(BUILD_SHARED_LIBS ON CACHE BOOL "Build shared libraries" FORCE)
endif()

# Set the default testing option
cmake_dependent_option(BUILD_TESTING "Enable testing" ON "CMAKE_PROJECT_NAME STREQUAL PROJECT_NAME" OFF)

# Set the default position-independent code option
cmake_dependent_option(CMAKE_POSITION_INDEPENDENT_CODE "Generate position-independent code" ON "BUILD_SHARED_LIBS" OFF)

# Dependencies Setup
include(cuda)

# Setup the test
if(BUILD_TESTING)
    include(CTest)
    add_subdirectory(test)
endif()

# Setup the library
string(TOLOWER ${PROJECT_NAME} PROJECT_NAME_LOWERCASE)
string(TOUPPER ${PROJECT_NAME} PROJECT_NAME_UPPERCASE)

configure_file(
    "${CMAKE_CURRENT_SOURCE_DIR}/cmake/version.h.in"
    "${CMAKE_CURRENT_SOURCE_DIR}/include/${PROJECT_NAME_LOWERCASE}/version.h"
    @ONLY
)

# Library Setup (In Case of Header Only)
add_library(${PROJECT_NAME}
    src/example_project.cpp
)
add_library(${PROJECT_NAME}::${PROJECT_NAME} ALIAS ${PROJECT_NAME})
target_include_directories(${PROJECT_NAME} PUBLIC
    $<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}/include>
    $<INSTALL_INTERFACE:include>)
target_compile_options(${PROJECT_NAME} PUBLIC
    -Wall # Enable all common warnings.
    -Wextra # Enable additional warnings not covered by -Wall.
    -pedantic # Enforce strict ISO C and ISO C++ compliance.
    -Wnon-virtual-dtor # Warn when a class with virtual functions has a non-virtual destructor.
    -Wold-style-cast # Warn about uses of old-style casts.
    -Wcast-align # Warn about potential performance problems with casts that increase alignment.
    -Wshadow # Warn when a variable declaration shadows a previous declaration.
    -Wunused # Warn about unused variables, functions, parameters, etc.
    -Wconversion # Warn for implicit type conversions that may change a value.
    -Wsign-conversion # Warn for implicit sign conversions.
    -Wnull-dereference # Warn if a null pointer dereference is detected.
    -Wdouble-promotion # Warn when a float is promoted to double.
    -Wmisleading-indentation # Warn about misleading indentation.
    -Wduplicated-cond # Warn about duplicated conditions in if-else-if chains.
    -Wduplicated-branches # Warn about duplicated branches in if-else-if chains.
    -Woverloaded-virtual # Warn when a function declaration hides a virtual function from a base class.
    -Wlogical-op # Warn about suspicious uses of logical operators.
    -Wuseless-cast # Warn if a cast does not change the type or value.

    # -Werror # Treat all warnings as errors.
)

# Executable Setup
add_executable(example_debug
    src/example_debug.cpp
)
target_compile_options(example_debug PUBLIC
    -g # Generate debug information
)

# CUDA executable example
if(CMAKE_CUDA_COMPILER)
    add_executable(example_cuda
        src/example_cuda.cu
    )
endif()

# Setup sanitizers
add_custom_target(sanitizer)
include(cppcheck)
include(clang-tidy)

# Setup the installation
include(GNUInstallDirs)
include(CMakePackageConfigHelpers)

install(TARGETS ${PROJECT_NAME}
    EXPORT ${PROJECT_NAME}Targets
    LIBRARY DESTINATION ${CMAKE_INSTALL_LIBDIR}
    ARCHIVE DESTINATION ${CMAKE_INSTALL_LIBDIR}
    RUNTIME DESTINATION ${CMAKE_INSTALL_BINDIR}
    INCLUDES DESTINATION ${CMAKE_INSTALL_INCLUDEDIR})

# Export targets
install(EXPORT ${PROJECT_NAME}Targets
    FILE ${PROJECT_NAME}Targets.cmake
    NAMESPACE ${PROJECT_NAME}::
    DESTINATION ${CMAKE_INSTALL_LIBDIR}/cmake/${PROJECT_NAME})

write_basic_package_version_file(
    "${CMAKE_CURRENT_BINARY_DIR}/${PROJECT_NAME}ConfigVersion.cmake"
    VERSION ${PROJECT_VERSION}
    COMPATIBILITY SameMajorVersion
)

configure_package_config_file(
    "${CMAKE_CURRENT_SOURCE_DIR}/cmake/${PROJECT_NAME}Config.cmake.in"
    "${CMAKE_CURRENT_BINARY_DIR}/${PROJECT_NAME}Config.cmake"
    INSTALL_DESTINATION ${CMAKE_INSTALL_LIBDIR}/cmake/${PROJECT_NAME}
)

install(FILES
    "${CMAKE_CURRENT_BINARY_DIR}/${PROJECT_NAME}Config.cmake"
    "${CMAKE_CURRENT_BINARY_DIR}/${PROJECT_NAME}ConfigVersion.cmake"
    DESTINATION ${CMAKE_INSTALL_LIBDIR}/cmake/${PROJECT_NAME}
)

# Setup the uninstall
if(NOT TARGET uninstall)
    configure_file(
        "${CMAKE_CURRENT_SOURCE_DIR}/cmake/cmake_uninstall.cmake.in"
        "${CMAKE_CURRENT_BINARY_DIR}/cmake_uninstall.cmake"
        IMMEDIATE @ONLY)

    add_custom_target(uninstall
        COMMAND ${CMAKE_COMMAND} -P ${CMAKE_CURRENT_BINARY_DIR}/cmake_uninstall.cmake)
endif()
