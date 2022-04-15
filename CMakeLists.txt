cmake_minimum_required(VERSION 3.17)
project(algorithms)

set(CMAKE_CXX_STANDARD 17)

add_executable(algorithms main.cpp strings/packed_prefix/strings_packed_prefix.cpp strings/packed_prefix/strings_packed_prefix_test.cpp)
