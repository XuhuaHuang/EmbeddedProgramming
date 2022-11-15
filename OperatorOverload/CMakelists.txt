cmake_minimum_required(VERSION 3.20)

project(OperatorOverload LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

# Adding multiple executable to the project
# Right-click on each item to set as start-up project
add_executable(AssignementOperator "assignment.cpp")
add_executable(ConversionOperator "conversion.cpp")
add_executable(InsertionExtractionOperator "insertion_extraction.cpp")
add_executable(ParenthesisOperator "parenthesis_fn_obj.cpp")
