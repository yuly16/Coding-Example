cmake_minimum_required(VERSION 3.20)
project(multiProjectDemo)

set(CMAKE_CXX_STANDARD 14)

add_subdirectory(A)
add_subdirectory(B)
add_subdirectory(apps)
