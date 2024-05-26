cmake_minimum_required(VERSION 3.20)

project("thread")

set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

# Adding multiple executable to the project
# Right-click on each item to set as start-up project
add_executable(atomic "atomic.cpp")
add_executable(create_threads "create_threads.cpp")
add_executable(thread_id "thread_id.cpp")
add_executable(thread_sleep "thread_sleep.cpp")
