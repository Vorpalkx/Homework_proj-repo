add_executable(bracket_balance 
    bracket_balance.c
    bracket_balance.h
    main.c
    string_filling.c
    string_filling.h
)

target_link_libraries(bracket_balance stack_lib)

target_include_directories(bracket_balance 
    PRIVATE 
        ${CMAKE_CURRENT_SOURCE_DIR}
)

target_compile_options(bracket_balance PRIVATE -Wall -Wextra)
