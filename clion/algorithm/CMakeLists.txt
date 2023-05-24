cmake_minimum_required(VERSION 3.22)
project(clion/algorithm)

set(CMAKE_CXX_STANDARD 14)

add_executable(algorithm
        leetcode/string_to_int.cpp)

add_executable(string_to_int leetcode/string_to_int.cpp)
add_executable(ACWing1 leetcode/ACWing1.cpp)
add_executable(ACWing leetcode/ACWing.cpp)
add_executable(ACWing2 leetcode/ACWing2.cpp)
add_executable(ACWing3 leetcode/ACWing3.cpp)
add_executable(ACWing4 leetcode/ACWing4.cpp)
add_executable(ACWing5 leetcode/ACWing5.cpp)
add_executable(ACWing6 leetcode/ACWing6.cpp)
add_executable(Test leetcode/Test.cpp)
add_executable(process1 os2022/process1.cpp)