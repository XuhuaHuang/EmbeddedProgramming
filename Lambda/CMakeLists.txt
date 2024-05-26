cmake_minimum_required(VERSION 3.20)

project("lambda")

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

# Adding multiple executable to the project
# Right-click on each item to set as start-up project
add_executable(lambda_functional "lambda_functional.cpp")
add_executable(generic_add "generic_add.cpp")
add_executable(notes "notes.cpp")
add_executable(scope "scope.cpp")
add_executable(lambda_with_stdlib "lambda_with_stdlib.cpp")

add_subdirectory("FunctorLambda")
