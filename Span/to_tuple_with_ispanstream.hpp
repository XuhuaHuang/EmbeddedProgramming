#pragma once
#include <span>
#include <spanstream>
#include <tuple>

template<class... Ts, auto N>
[[nodiscard]] constexpr auto to_tuple(char (&input)[N])
{
    constexpr auto extract = []<class T>(auto& input) -> T {
        T t{};
        input >> t;
        return t;
    };
    std::ispanstream is{input};
    return std::tuple{extract.template operator()<Ts>(is)...};
}
