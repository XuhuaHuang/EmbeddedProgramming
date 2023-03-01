cmake_minimum_required(VERSION 3.20)

project(ModuleExample)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

add_library(ExampleModule
	"ModuleExample/Example.ixx"
)

add_executable(example_module_exec
    "ModuleExample/MyProgram.cpp"
)

target_link_libraries(example_module_exec ExampleModule)
