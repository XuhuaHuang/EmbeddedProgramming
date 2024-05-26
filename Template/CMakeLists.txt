cmake_minimum_required(VERSION 3.20)

project("template")

set(CMAKE_CXX_STANDARD 23)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

add_executable(template_cls
    "ClassTemplate/main.cpp"
    "ClassTemplate/Stack.hpp"
)

add_executable(template_fn
    "FunctionTemplate/main.cpp"
    "FunctionTemplate/max.hpp"
)

# add_executable(TemplateNotes
#     "template_notes.h"
#     "template_notes.cpp"
# )
