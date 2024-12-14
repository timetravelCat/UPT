// Copyright 2024 timetravelCat
//
// Licensed under the Apache License, Version 2.0 (the "License");
// you may not use this file except in compliance with the License.
// You may obtain a copy of the License at
//
//     https://www.apache.org/licenses/LICENSE-2.0
//
// Unless required by applicable law or agreed to in writing, software
// distributed under the License is distributed on an "AS IS" BASIS,
// WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
// See the License for the specific language governing permissions and
// limitations under the License.

#if defined(Catch2_VERSION_MAJOR) && Catch2_VERSION_MAJOR == 2
#define CATCH_CONFIG_MAIN
#include <catch2/catch.hpp>
#elif defined(Catch2_VERSION_MAJOR) && Catch2_VERSION_MAJOR == 3
#include <catch2/catch_test_macros.hpp>
#else
#error "Unsupported Catch2 version"
#endif

unsigned int Factorial(unsigned int number) {
    return number <= 1 ? number : Factorial(number - 1) * number;
}

TEST_CASE("Factorials are computed", "[factorial]") {
    REQUIRE(Factorial(1) == 1);
    REQUIRE(Factorial(2) == 2);
    REQUIRE(Factorial(3) == 6);
    REQUIRE(Factorial(10) == 3628800);
}
