// cl /W4 /Zc:__cplusplus /EHsc /std:c++latest /exportHeader .\fixed_string.hpp

#ifndef FIXED_STRING_HPP
#define FIXED_STRING_HPP

#include <array>
#include <string_view>
#include <type_traits>
#include <xutility>

namespace util {
namespace type {

template <char...>
struct ct_string {};

template <class T, T... Cs>
constexpr auto operator""_cs() {
    return ct_string<Cs...>{};
}

template <std::size_t N>
struct fixed_string final {
    constexpr explicit(true) fixed_string(const auto... cs)
        : data{cs...} {}

    constexpr explicit(false) fixed_string(const char (&str)[N + 1]) { std::copy_n(str, N + 1, std::data(data)); }

    [[nodiscard]]
    constexpr auto operator<=>(const fixed_string&) const = default;

    [[nodiscard]] constexpr explicit(false) operator std::string_view() const { return {std::data(data), N}; }

    [[nodiscard]]
    constexpr auto size() const -> std::size_t {
        return N;
    }

    std::array<char, N + 1> data{};
};

template <fixed_string Str>
static auto to_string = []<auto... Ns>(std::index_sequence<Ns...>) {
    return ct_string<Str.data[Ns]...>{};
}(std::make_index_sequence<Str.size()>{});

static_assert(ct_string<'h', 'e', 'l', 'l', 'o'> == to_string<"hello">());

template <fixed_string Str>
using to_string_t = decltype([]<auto... Is>(std::index_sequence<Is...>) {
    return ct_string<Str[Is]...>{};
}(std::make_index_sequence<std::size(Str) - 1>{}));

} // namespace type
} // namespace util

#endif // !FIXED_STRING_HPP
