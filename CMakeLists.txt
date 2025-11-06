cmake_minimum_required(VERSION 3.10)
project(MyProject C)

set(CMAKE_C_STANDARD 11)
set(CMAKE_C_STANDARD_REQUIRED ON)

add_subdirectory(src/Stack)
add_subdirectory(src/Advanced\ bracket\ balance)
add_subdirectory(src/Shunting\ yard)

# Опционально: создание псевдоцели для удобства
add_custom_target(build_all DEPENDS bracket_balance shunting_yard)
