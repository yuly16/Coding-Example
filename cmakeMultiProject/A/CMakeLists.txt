project(A)
add_library(${PROJECT_NAME} SHARED
        add.cpp
        )

target_link_libraries(${PROJECT_NAME}
        PUBLIC
        B
        )

target_include_directories (A
        PUBLIC
        ${CMAKE_CURRENT_SOURCE_DIR}/include)