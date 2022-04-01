cmake_minimum_required(VERSION 3.20)
project(cyclereference)

set(CMAKE_CXX_STANDARD 11)
add_executable(sharedptr sharedptr.cpp)
add_executable(weakptr weakptr.cpp)