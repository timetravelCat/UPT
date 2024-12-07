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

# * Run cppcheck by cmake --build build --target cppcheck
# * Outputs cppcheck.xml in the build directory

find_program(CPPCHECK_EXECUTABLE NAMES cppcheck)

if(CPPCHECK_EXECUTABLE AND CMAKE_EXPORT_COMPILE_COMMANDS)
    add_custom_target(cppcheck
        COMMAND ${CPPCHECK_EXECUTABLE}
        --project=${CMAKE_BINARY_DIR}/compile_commands.json
        --output-file=${CMAKE_BINARY_DIR}/cppcheck.xml
        COMMAND ${CMAKE_COMMAND} -E cat ${CMAKE_BINARY_DIR}/cppcheck.xml
        WORKING_DIRECTORY ${CMAKE_SOURCE_DIR}
        COMMENT "Running cppcheck"
    )

    add_dependencies(sanitizer cppcheck)
endif()
