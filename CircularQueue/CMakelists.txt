cmake_minimum_required(VERSION 3.21)

project(CircularQueueCStyle)

set(C_STANDARD 17)
set(C_STANDARD_REQUIRED ON)

add_executable(CircularQueueCStyle
    "queue_array.c"
)
