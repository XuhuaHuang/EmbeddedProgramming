cmake_minimum_required ( VERSION 3.20 )

project ( "Tree"
    VERSION 1.0.0
    DESCRIPTION "Tree Data Structure"
    LANGUAGES C CXX
)

set ( CMAKE_C_STANDARD 17 )
set ( CMAKE_C_STANDARD_REQUIRED ON )
set ( CMAKE_C_EXTENSIONS OFF )

set ( CMAKE_CXX_STANDARD 23 )
set ( CMAKE_CXX_STANDARD_REQUIRED ON )

add_executable ( binary_search_tree "search_tree.c" )

if ( MSVC )
    target_compile_options ( binary_search_tree PRIVATE /W4 /permissive- /Zc:__cplusplus /EHsc /std:c++latest /experimental:module )
else ()
    target_compile_options ( binary_search_tree PRIVATE -Wall -Wextra -pedantic -Werror )
endif ()
