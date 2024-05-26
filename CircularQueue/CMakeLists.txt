cmake_minimum_required(VERSION 3.20)

project(circular_queue)

set(C_STANDARD 17)
set(C_STANDARD_REQUIRED ON)

add_executable(circular_queue
    "queue_array.c"
)
