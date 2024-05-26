cmake_minimum_required(VERSION 3.20)

project("concept")

set(CMAKE_CXX_STANDARD 23)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

# Adding multiple executable to the project
# Right-click on each item to set as start-up project
add_executable(has_push_back
    "HasPushBack.hpp"
    "usecase_haspushback.cpp"
)

add_executable(supports_comparison
    "SupportsComparison.hpp"
    "usecase_comparison.cpp"
)
