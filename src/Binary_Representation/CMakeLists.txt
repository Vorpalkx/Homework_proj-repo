add_executable(binary_representation 
    binary_operations.c
    binary_operations.h
    main.c
    binary_operations_tests.c
    binary_operations_tests.h
)

target_link_libraries(binary_representation stack_lib)

target_include_directories(binary_representation
    PRIVATE 
        ${CMAKE_CURRENT_SOURCE_DIR}
)

target_compile_options(binary_representation PRIVATE -Wall -Wextra)
