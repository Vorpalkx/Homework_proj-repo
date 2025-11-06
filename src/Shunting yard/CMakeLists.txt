add_executable(shunting_yard 
    filling_expression.c
    filling_expression.h
    main.c
)

target_link_libraries(shunting_yard stack_lib)

target_include_directories(shunting_yard 
    PRIVATE 
	${CMAKE_CURRENT_SOURCE_DIR}
)

target_compile_options(shunting_yard PRIVATE -Wall -Wextra)
