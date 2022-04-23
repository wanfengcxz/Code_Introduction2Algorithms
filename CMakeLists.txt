cmake_minimum_required(VERSION 3.19)
project(Code_Introduction2Algorithms)

set(CMAKE_CXX_STANDARD 14)

# googletest
add_subdirectory(lib)
include_directories(googletest/include googletest)

add_executable(Code_Introduction2Algorithms main.cpp)

# chapter04
add_executable(maximum_subarray_test ./chapter04/MaximumSubarray/maximum_subarray_test.cpp)
target_link_libraries(maximum_subarray_test gtest gtest_main)