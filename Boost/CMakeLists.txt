cmake_minimum_required(VERSION 3.20)

# ┌──────────────────────────────────────────────────────────────────┐
# │  Projects Settings                                               │
# └──────────────────────────────────────────────────────────────────┘
project(BoostExamples
    VERSION 1.0.0
    DESCRIPTION "Examples on using boost library"
    LANGUAGES CXX
)

# ┌──────────────────────────────────────────────────────────────────┐
# │  CXX Standard Requirements                                       │
# └──────────────────────────────────────────────────────────────────┘
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

set(CMAKE_INCLUDE_CURRENT_DIR ON)

# ┌──────────────────────────────────────────────────────────────────┐
# │  Sub-directories with CMake                                      │
# └──────────────────────────────────────────────────────────────────┘
add_subdirectory("Common")
add_subdirectory("LambdaExample")
add_subdirectory("TimeDate")
