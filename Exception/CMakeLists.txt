cmake_minimum_required(VERSION 3.20)

# Project definition
project(exception
    VERSION 1.0
    DESCRIPTION "Modern C++ Exception Handling Examples"
    LANGUAGES CXX
)

# Enforce modern C++ standard
set(CMAKE_CXX_STANDARD 23)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS OFF)

# Create executable
add_executable(${PROJECT_NAME}
    basic.cpp
)

# Compiler warnings (portable)
if(MSVC)
    target_compile_options(${PROJECT_NAME} PRIVATE /W4 /permissive-)
else()
    target_compile_options(${PROJECT_NAME} PRIVATE -Wall -Wextra -Wpedantic)
endif()

# Optional: Enable optimizations for Release builds
target_compile_options(${PROJECT_NAME} PRIVATE
    $<$<CONFIG:Release>:-O3>
)

# Optional: Enable debug symbols
target_compile_options(${PROJECT_NAME} PRIVATE
    $<$<CONFIG:Debug>:-g>
)

# Organize output directories (clean structure)
set_target_properties(${PROJECT_NAME} PROPERTIES
    RUNTIME_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/bin
)
