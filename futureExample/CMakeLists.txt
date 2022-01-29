cmake_minimum_required(VERSION 3.20)
project(futuredemo)

set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_FLAGS -pthread)
add_executable(async_demo main_async.cpp)
add_executable(future_demo main_future.cpp)
add_executable(promise_demo main_promise.cpp)