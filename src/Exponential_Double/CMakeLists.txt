add_executable(exponential_form 
    exponential_form.c
    exponential_form.h
    main.c
)

target_link_libraries(exponential_form stack_lib)

target_include_directories(exponential_form
    PRIVATE 
        ${CMAKE_CURRENT_SOURCE_DIR}
)

target_compile_options(exponential_form PRIVATE -Wall -Wextra)
