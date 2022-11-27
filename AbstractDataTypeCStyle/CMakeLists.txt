cmake_minimum_required(VERSION 3.21)

project(AbstractDataTypeCStyle)

set(C_STANDARD 17)
set(C_STANDARD_REQUIRED ON)

add_executable(AbstractDataTypeCStyle
    "queue.h"
    "queue.c"
    "main.c"
)
