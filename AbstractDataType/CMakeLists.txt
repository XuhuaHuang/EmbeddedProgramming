cmake_minimum_required(VERSION 3.20)

project("abstract_dtype" LANGUAGES C)

set(C_STANDARD 17)
set(C_STANDARD_REQUIRED ON)

add_executable(abstract_dtype
    "queue.h"
    "queue.c"
    "main.c"
)
