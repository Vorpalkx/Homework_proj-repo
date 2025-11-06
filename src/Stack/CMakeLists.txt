add_library(stack_lib 
    stack.c
    stack.h
)

target_include_directories(stack_lib 
    PUBLIC 
        ${CMAKE_CURRENT_SOURCE_DIR}
)

target_compile_options(stack_lib PRIVATE -Wall -Wextra)
