cmake_minimum_required(VERSION 3.20)

project("module")

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

add_library(module
	"ModuleExample/Example.ixx"
)

add_executable(module_program
    "ModuleExample/MyProgram.cpp"
)

target_link_libraries(module_program module)
