cmake_minimum_required(VERSION 3.20 FATAL_ERROR)

project(raw_linear_regression LANGUAGES CXX)

option(RAW_LINEAR_REGRESSION_ENABLE_SANITIZERS
    "Enable AddressSanitizer and UndefinedBehaviorSanitizer for regression targets." OFF)
if(RAW_LINEAR_REGRESSION_ENABLE_SANITIZERS AND
   NOT CMAKE_CXX_COMPILER_ID MATCHES "GNU|Clang")
    message(FATAL_ERROR "Regression sanitizers require a GCC or Clang toolchain.")
endif()

function(configure_regression_target target_name)
    target_compile_features(${target_name} PRIVATE cxx_std_23)
    set_target_properties(${target_name} PROPERTIES CXX_EXTENSIONS OFF)
    target_include_directories(${target_name} PRIVATE "${CMAKE_CURRENT_SOURCE_DIR}")
    if(MSVC)
        target_compile_options(${target_name} PRIVATE /W4 /Zc:__cplusplus /EHsc)
    elseif(CMAKE_CXX_COMPILER_ID MATCHES "GNU|Clang")
        target_compile_options(${target_name} PRIVATE -Wall -Wextra -Wpedantic)
    endif()
    if(RAW_LINEAR_REGRESSION_ENABLE_SANITIZERS)
        target_compile_options(${target_name} PRIVATE
            -fsanitize=address,undefined -fno-omit-frame-pointer -fno-sanitize-recover=all)
        target_link_options(${target_name} PRIVATE
            -fsanitize=address,undefined -fno-sanitize-recover=all)
    endif()
endfunction()

add_executable(raw_linear_regression main.cpp raw_linear_regression.hpp)
configure_regression_target(raw_linear_regression)

include(CTest)
if(BUILD_TESTING)
    add_executable(raw_linear_regression_tests raw_linear_regression_unittest.cpp)
    configure_regression_target(raw_linear_regression_tests)
    add_test(NAME raw_linear_regression_tests COMMAND raw_linear_regression_tests)

    if(NOT TARGET GTest::gtest_main)
        find_package(GTest QUIET)
    endif()
    if(TARGET GTest::gtest_main)
        add_executable(raw_linear_regression_gtests gtest_raw_linear_regression.cpp)
        configure_regression_target(raw_linear_regression_gtests)
        target_link_libraries(raw_linear_regression_gtests PRIVATE GTest::gtest_main)
        include(GoogleTest)
        gtest_discover_tests(raw_linear_regression_gtests)
    endif()
endif()
