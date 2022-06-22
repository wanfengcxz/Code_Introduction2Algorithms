cmake_minimum_required(VERSION 3.19)
project(Code_Introduction2Algorithms)

set(CMAKE_CXX_STANDARD 14)

# googletest
add_subdirectory(lib)
include_directories(googletest/include googletest)

add_executable(Code_Introduction2Algorithms main.cpp)

# chapter04
add_executable(maximum_subarray ./chapter04/MaximumSubarray/maximum_subarray.cpp)
add_executable(maximum_subarray_test ./chapter04/MaximumSubarray/maximum_subarray_test.cpp)
target_link_libraries(maximum_subarray_test gtest gtest_main)

#chapter15
add_executable(cut_rod ./chapter15/CutRod/cut_rod.cpp)
add_executable(fibonacci_seq chapter15/LeetCode/fibonacci_seq.cpp)
add_executable(climb_stairs chapter15/LeetCode/climb_stairs.cpp)
add_executable(min_cost_climbing_stairs chapter15/LeetCode/min_cost_climbing_stairs.cpp)
add_executable(rob chapter15/LeetCode/rob.cpp)
add_executable(rob2 chapter15/LeetCode/rob2.cpp)
add_executable(delete_and_earn chapter15/LeetCode/delete_and_earn.cpp)

