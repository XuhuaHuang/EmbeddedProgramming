cmake_minimum_required(VERSION 3.20)

project(GoogleTest)

# GoogleTest requires at least C++14
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

include(FetchContent)
FetchContent_Declare(
    googletest
    URL https://github.com/google/googletest/archive/03597a01ee50ed33e9dfd640b249b4be3799d395.zip
)

# For Windows: Prevent overriding the parent project's compiler/linker settings
set(gtest_force_shared_crt ON CACHE BOOL "" FORCE)
FetchContent_MakeAvailable(googletest)

enable_testing()

# Adding multiple executable to the project
# Right-click on each item to set as start-up project

# GoogleTest project setup test
add_executable(
    hello_test
    hello_test.cpp
)

# GoogleTest for basice implementation of Queue
add_executable(
    queue_test
    queue_test.cpp
)

# GoogleTest for basic implementation of Factorial function
add_executable(
    factorial_test
    factorial_test.cpp
)

# GoogleTest for basic implementation of BankAccount
add_executable(
    bank_account_test
    bank_account_test.cpp
)

target_link_libraries(
    hello_test
    GTest::gtest_main
)

target_link_libraries(
    queue_test
    GTest::gtest_main
)

target_link_libraries(
    factorial_test
    GTest::gtest_main
)

target_link_libraries(
    bank_account_test
    GTest::gtest_main
)

include(GoogleTest)

# Make added executables discoved by GTest
gtest_discover_tests(
    hello_test
    queue_test
    factorial_test
    bank_account_test
)
