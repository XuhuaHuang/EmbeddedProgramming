cmake_minimum_required(VERSION 3.21)

project("algorithm")

set(CMAKE_CXX_STANDARD 23)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

add_executable(merge "merge.cpp")

# Assign value by relative path
# The relative path with respect to current file MUST change if this instruction block is reused
get_filename_component(REPO_ROOT_DIR ../../ ABSOLUTE)

target_include_directories(merge
    PUBLIC
        ${REPO_ROOT_DIR}
        ${REPO_ROOT_DIR}/Helper
        ${REPO_ROOT_DIR}/Util
)
