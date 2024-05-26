cmake_minimum_required(VERSION 3.20)

project("sfml_cmake" LANGUAGES CXX)

include(FetchContent)
FetchContent_Declare(SFML
    GIT_REPOSITORY https://github.com/SFML/SFML.git
    GIT_TAG 2.6.x)
FetchContent_MakeAvailable(SFML)

add_executable(sfml_cmake "Example/main.cpp")
target_link_libraries(sfml_cmake PRIVATE sfml-graphics)
target_compile_features(sfml_cmake PRIVATE cxx_std_17)

if (WIN32 AND BUILD_SHARED_LIBS)
    add_custom_command(TARGET sfml_cmake POST_BUILD
        COMMAND ${CMAKE_COMMAND} -E copy $<TARGET_RUNTIME_DLLS:sfml_cmake> $<TARGET_FILE_DIR:sfml_cmake> COMMAND_EXPAND_LISTS)
endif()

install(TARGETS sfml_cmake)
