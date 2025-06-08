cmake_minimum_required(VERSION 3.20)

project(LookupTable
    VERSION 1.0
    DESCRIPTION "A modern C project using a lookup table"
    LANGUAGES C
)

# Set C standard
set(CMAKE_C_STANDARD 17)
set(CMAKE_C_STANDARD_REQUIRED ON)
set(CMAKE_C_EXTENSIONS OFF)

# Enable more warnings on MSVC or GCC/Clang
if(MSVC)
    add_compile_options(/W4 /permissive-)
else()
    add_compile_options(-Wall -Wextra -pedantic -Werror)
endif()

# Define the executable
add_executable(square_table square_table.c)
add_executable(generate_cube generate_cube.c)
