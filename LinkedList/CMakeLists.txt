cmake_minimum_required(VERSION 3.20)

project("linked_list")

set(C_STANDARD 17)
set(C_STANDARD_REQUIRED ON)

add_executable(linked_list "linked_list.c")
add_executable(sort_linked_list_cli "sort_linked_list_cli.c")
