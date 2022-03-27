project(B)
set(CMAKE_POSITION_INDEPENDENT_CODE ON)
add_library(${PROJECT_NAME} STATIC
        sub.cpp
        )
target_include_directories (B
        PUBLIC
        ${CMAKE_CURRENT_SOURCE_DIR}/include)