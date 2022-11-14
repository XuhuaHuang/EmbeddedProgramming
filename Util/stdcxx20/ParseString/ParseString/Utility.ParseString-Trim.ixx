export module Utility.ParseString:Trim;

#if defined __has_include
#if __has_include(<ranges>) && __has_include(<string>)
#include <ranges>
#include <string>
#else
#error "Require std::ranges and std::string library!"
#endif
#endif

export constexpr auto trim_front = std::views::drop_while(::isspace);

export constexpr auto trim_back = std::views::reverse
    | std::views::drop_while(::isspace)
    | std::views::reverse;

export auto trim_spaces = trim_front | trim_back;
