cmake_minimum_required(VERSION 3.20)

project(Concept)

set(CMAKE_CXX_STANDARD 23)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

# Adding multiple executable to the project
# Right-click on each item to set as start-up project
add_executable(HasPushBack
    "HasPushBack.hpp"
    "usecase_haspushback.cpp"
)

add_executable(SupportsComparison
    "SupportsComparison.hpp"
    "usecase_comparison.cpp"
)
