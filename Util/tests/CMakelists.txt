cmake_minimum_required(VERSION 3.20)

project(UtilityTests)

set(CMAKE_CXX_STANDARD 23)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

get_filename_component(UTIL_ROOT ../ ABSOLUTE)
include_directories(${UTIL_ROOT})

# Adding multiple executable to the project
# Right-click on each item to set as start-up project
add_executable(is_instance_of "${UTIL_ROOT}/is_instance_of.hpp" "test_is_instance_of.cpp")
add_executable(parse_str "${UTIL_ROOT}/parse.hpp" "${UTIL_ROOT}/print_vec.hpp" "test_parse_str.cpp")
add_executable(safe_free "${UTIL_ROOT}/safe_free.hpp" "test_safe_free.cpp")

# Adding Google Test component
# Fetch content from GitHub archive
include(FetchContent)
FetchContent_Declare(
    googletest
    URL https://github.com/google/googletest/archive/03597a01ee50ed33e9dfd640b249b4be3799d395.zip
)

# For Windows: Prevent overriding the parent project's compiler/linker settings
set(gtest_force_shared_crt ON CACHE BOOL "" FORCE)
FetchContent_MakeAvailable(googletest)

enable_testing()

# GoogleTest for trim_str implementation
add_executable(gtest_trim_str "${UTIL_ROOT}/trimstr.hpp" "gtest_trim_str.cpp")
target_link_libraries(gtest_trim_str GTest::gtest_main)
include(GoogleTest)

# Make added executables discoved by GTest
gtest_discover_tests(gtest_trim_str)
