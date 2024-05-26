cmake_minimum_required(VERSION 3.20)

# ┌──────────────────────────────────────────────────────────────────┐
# │  Projects Settings                                               │
# └──────────────────────────────────────────────────────────────────┘
project("dealer"
    VERSION 1.0.0
    DESCRIPTION "Legacy and refactored Dealer project with unit tests"
    LANGUAGES CXX
)

# ┌──────────────────────────────────────────────────────────────────┐
# │  Sub-directories with CMake                                      │
# └──────────────────────────────────────────────────────────────────┘
add_subdirectory("Legacy")
add_subdirectory("Refactored")
