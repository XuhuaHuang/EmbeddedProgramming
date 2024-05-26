cmake_minimum_required(VERSION 3.20)

project("lambda")

set(CMAKE_CXX_STANDARD 23)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

add_executable(lambda "lambda.cpp")

target_include_directories(lambda PUBLIC "C:\\boost\\boost_1_82_0")
