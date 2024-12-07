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

# * Run clang-tidy by cmake --build build --target clang-tidy
# * Outputs clang-tidy.log in the build directory

find_program(CLANG_TIDY_EXECUTABLE NAMES clang-tidy)

# List all c/cpp source files in the project
file(GLOB_RECURSE ALL_SOURCE_FILES
    RELATIVE ${CMAKE_SOURCE_DIR}
    CONFIGURE_DEPENDS
    "*.c" "*.cpp" "*.h" "*.hpp" "*.cxx" "*.hxx" "*.cc" "*.hh"
)

# Convert CMAKE_BINARY_DIR to a relative path
file(RELATIVE_PATH RELATIVE_BINARY_DIR ${CMAKE_SOURCE_DIR} ${CMAKE_BINARY_DIR})
list(FILTER ALL_SOURCE_FILES EXCLUDE REGEX "${RELATIVE_BINARY_DIR}/")

if(CLANG_TIDY_EXECUTABLE AND CMAKE_EXPORT_COMPILE_COMMANDS)
    add_custom_target(clang-tidy
        COMMAND ${CLANG_TIDY_EXECUTABLE} > ${CMAKE_BINARY_DIR}/clang-tidy.log
        -p=${CMAKE_BINARY_DIR}
        ${ALL_SOURCE_FILES}
        COMMAND ${CMAKE_COMMAND} -E cat ${CMAKE_BINARY_DIR}/clang-tidy.log
        WORKING_DIRECTORY ${CMAKE_SOURCE_DIR}
        COMMENT "Running clang-tidy"
    )

    add_dependencies(sanitizer clang-tidy)
endif()
