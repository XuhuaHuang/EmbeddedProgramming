cmake_minimum_required(VERSION 3.20)

project(Lambda)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

# Adding multiple executable to the project
# Right-click on each item to set as start-up project
add_executable(ForEachWithLambda "lambda_functional.cpp")
add_executable(GenericAdd "generic_add.cpp")
add_executable(LambdaBasics "lambda_notes.cpp")
add_executable(LambdaScopeDemo "lambda_scope_demo.cpp")
add_executable(LambdaWithStdSortAlgo "lambda_with_stdlib.cpp")

add_subdirectory("FunctorLambda")
