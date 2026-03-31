cmake_minimum_required(VERSION 3.28)
project(DungeonRPG)

set(CMAKE_CXX_STANDARD 23)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_EXPORT_COMPILE_COMMANDS ON)

# Tell compiler to find headers
include_directories(src/core)

# The executable
add_executable(dungeon src/main.cpp)

include(FetchContent)
FetchContent_Declare(
    googletest
    URL https://github.com/google/googletest/archive/refs/tags/v1.14.0.zip
)
FetchContent_MakeAvailable(googletest)

include(GoogleTest)
enable_testing()

# add_executable(tests tests/main_test.cpp src/game/combat.cpp)
# target_link_libraries(tests gtest_main)
# gtest_discover_tests(tests)
