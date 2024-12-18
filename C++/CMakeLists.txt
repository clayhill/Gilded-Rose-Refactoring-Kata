cmake_minimum_required(VERSION 3.29)
project(GildedRose)

set(CMAKE_CXX_STANDARD 20)

include(FetchContent)

FetchContent_Declare(
    googletest
    URL https://github.com/google/googletest/releases/download/v1.15.2/googletest-1.15.2.tar.gz
)

FetchContent_MakeAvailable(googletest)

enable_testing()

add_executable(testbench
    src/gilded_rose.h
    src/gilded_rose.cpp
    tests/gilded_rose_tests.cpp
)

target_include_directories(testbench PRIVATE src)
target_link_libraries(testbench
    gmock_main
    gmock
)

include(GoogleTest)
gtest_discover_tests(testbench)