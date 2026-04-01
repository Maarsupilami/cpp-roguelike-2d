cmake_minimum_required(VERSION 3.28)
project(DungeonRPG)

# ── Language standard ─────────────────────────────────────────────────────────
set(CMAKE_CXX_STANDARD 23)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_EXPORT_COMPILE_COMMANDS ON)  # for clangd / IDE tooling

# ── Dependencies ──────────────────────────────────────────────────────────────
find_package(SFML 3 COMPONENTS Graphics Window System REQUIRED)

include(FetchContent)
FetchContent_Declare(
    googletest
    URL https://github.com/google/googletest/archive/refs/tags/v1.14.0.zip
)
FetchContent_MakeAvailable(googletest)

# ── core_lib (INTERFACE — header-only) ────────────────────────────────────────
# INTERFACE means no compilation; just propagates include paths to consumers.
add_library(core_lib INTERFACE)
target_include_directories(core_lib INTERFACE src/core)

# ── dungeon (main executable) ─────────────────────────────────────────────────
add_executable(dungeon
    src/main.cpp
    src/game/game.cpp
    src/game/map.cpp
    src/game/render.cpp
)
target_link_libraries(dungeon
    SFML::Graphics
    SFML::Window
    SFML::System
    core_lib
)

add_custom_command(TARGET dungeon POST_BUILD
    COMMAND ${CMAKE_COMMAND} -E copy_directory
        ${CMAKE_SOURCE_DIR}/assets
        $<TARGET_FILE_DIR:dungeon>/assets
)

# ── tests ─────────────────────────────────────────────────────────────────────
# Tests link core_lib only — no SFML dependency in unit tests.
include(GoogleTest)
enable_testing()

add_executable(tests tests/main_test.cpp)
target_link_libraries(tests gtest_main core_lib)
gtest_discover_tests(tests)
