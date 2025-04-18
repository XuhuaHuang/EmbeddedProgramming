cmake_minimum_required(VERSION 3.20)

project("google_test" LANGUAGES C CXX)

# GoogleTest requires at least C++14
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

cmake_policy(SET CMP0135 NEW)
include(FetchContent)
FetchContent_Declare(
    googletest
    URL https://github.com/google/googletest/archive/refs/tags/v1.16.0.zip
    DOWNLOAD_EXTRACT_TIMESTAMP TRUE
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
    "hello_test.cpp"
)
add_test(NAME hello_test COMMAND hello_test)

# GoogleTest for basic implementation of Queue
add_executable(
    queue_test
    "queue_test.cpp"
)
add_test(NAME queue_test COMMAND queue_test)

# GoogleTest for basic implementation of Factorial function
add_executable(
    factorial_test
    "factorial_test.cpp"
)
add_test(NAME factorial_test COMMAND factorial_test)

# GoogleTest for basic implementation of BankAccount
add_executable(
    bank_account_test
    "bank_account_test.cpp"
)
add_test(NAME bank_account_test COMMAND bank_account_test)

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

# Make added executables discovered by GTest
gtest_discover_tests(
    hello_test
    queue_test
    factorial_test
    bank_account_test
)
