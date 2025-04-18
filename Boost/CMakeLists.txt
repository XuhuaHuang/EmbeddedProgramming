cmake_minimum_required(VERSION 3.20)

project("boost_examples"
    VERSION 1.0.0
    DESCRIPTION "Examples on using boost library"
    LANGUAGES CXX
)

find_package(Boost REQUIRED)

include_directories(${Boost_INCLUDE_DIRS})

add_subdirectory("Assign")
add_subdirectory("Common")
add_subdirectory("ComparablePoint")
add_subdirectory("CurrentFunctionMacro")
add_subdirectory("Fusion")
add_subdirectory("LambdaExample")
add_subdirectory("LinearRegression")
add_subdirectory("MultiArray")
add_subdirectory("Proto")
add_subdirectory("StringRef")
add_subdirectory("TimeDate")
add_subdirectory("TypeIndex")
