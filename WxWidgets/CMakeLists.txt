cmake_minimum_required(VERSION 3.20)
project(wx_starter LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 23)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

add_executable(wx_starter widget.cpp)

# wxWidgets CMake package naming varies by installation method.
# Most modern installs provide an imported target `wx::wxwidgets`.
# Ubuntu/Debian commonly use FindwxWidgets.cmake (module mode), not CONFIG.
find_package(wxWidgets REQUIRED COMPONENTS core base)

include(${wxWidgets_USE_FILE})
target_link_libraries(wx_starter PRIVATE ${wxWidgets_LIBRARIES})

# Quality-of-life warnings (tune per compiler)
if (MSVC)
  target_compile_options(wx_starter PRIVATE /W4 /permissive-)
else()
  target_compile_options(wx_starter PRIVATE -Wall -Wextra -Wpedantic)
endif()
