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

# * Catch2 2.13.8 is used in jammy
# * Catch2 3.4.0 is used in noble
find_package(Catch2)

if(NOT Catch2_FOUND)
    message(STATUS "Catch2 not found, testing disabled.")
    return()
endif()

# This is a workaround for Catch2 2.13.8
include(Catch)
set(CATCH_BUILD_TESTING OFF CACHE BOOL "Build Catch2's own tests" FORCE)
set(CATCH_INSTALL_DOCS OFF CACHE BOOL "Install Catch2's documentation" FORCE)

file(GLOB src CONFIGURE_DEPENDS *.cpp *.c *.cxx *.cc)

foreach(target ${src})
    get_filename_component(target_name ${target} NAME_WE)
    add_executable(${target_name} ${target})
    target_link_libraries(${target_name} PRIVATE
        Catch2::Catch2 # WARN Catch2::Catch2WithMain if you are using newer version of Catch2
        ${PROJECT_NAME})
    add_test(NAME ${target_name} COMMAND ${target_name})
    catch_discover_tests(${target_name})
endforeach(target)
