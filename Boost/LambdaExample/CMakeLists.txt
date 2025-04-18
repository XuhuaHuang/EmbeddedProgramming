cmake_minimum_required(VERSION 3.20)

project("lambda")

set(CMAKE_CXX_STANDARD 23)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

# Find Boost via vcpkg
find_package(Boost REQUIRED)

add_executable(lambda "lambda.cpp")

# Explicitly add Boost include directories if needed
target_include_directories(lambda PUBLIC ${Boost_INCLUDE_DIRS})

target_link_libraries(lambda PUBLIC ${Boost_LIBRARIES})
