cmake_minimum_required(VERSION 3.20)

project(abstract_dtype LANGUAGES C)

set(CMAKE_C_STANDARD 17)
set(CMAKE_C_STANDARD_REQUIRED ON)

set(CMAKE_EXPORT_COMPILE_COMMANDS ON)

add_executable(abstract_dtype
    queue.h
    queue.c
    main.c
)

include(CTest)
if(BUILD_TESTING)
    add_executable(abstract_dtype_queue_creation_test
        tests/queue_creation_test.c
    )
    target_include_directories(abstract_dtype_queue_creation_test PRIVATE "${CMAKE_CURRENT_LIST_DIR}")
    add_test(NAME abstract_dtype.queue_creation
        COMMAND abstract_dtype_queue_creation_test
    )
endif()
