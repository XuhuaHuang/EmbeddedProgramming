/**
 * @file lambda_typed_min_max.cpp
 * @author Xuhua Huang
 * @brief
 * @version 0.1
 * @date 2023-06-11
 *
 * @copyright Copyright (c) 2023
 *
 */

#include <iostream>
#include <stdfloat>
#include <type_traits>

template<auto Func, typename... Ts>
constexpr auto min_max(std::tuple<Ts...>&& tuple) -> std::tuple<size_t, size_t>
{
    using tuple_t                                         = typename std::remove_cvref_t<decltype(tuple)>;
    std::array<size_t, std::tuple_size_v<tuple_t>> buffer = {};

    []<size_t... Is>(auto&& tuple, auto& out, std::index_sequence<Is...> indicies) {
        (static_cast<void>(out[Is] = Func.template operator()<std::tuple_element_t<Is, tuple_t>>()), ...);
    }(std::forward<decltype(tuple)>(tuple), buffer, std::make_index_sequence<std::tuple_size_v<tuple_t>>{});

    const auto [min, max] = std::ranges::minmax(buffer);
    return {min, max};
}

template<auto predicate, typename... Ts>
constexpr std::tuple<std::size_t, std::size_t> min_max_template_operator(std::tuple<Ts...>&& tuple)
{
    return std::minmax({predicate.template operator()<Ts>()...});
}

template<auto P>
auto min_max_with_apply = [](auto t) {
    const auto values =
        std::apply([&]<class... F>(F&... floats) { return std::make_tuple(P.template operator()<F>()...); }, t);

    const auto min = std::apply([](auto&&... args) { return (std::min({args...})); }, values);
    const auto max = std::apply([](auto&&... args) { return (std::max({args...})); }, values);

    return std::tuple(min, max);
};

int main()
{
    static_assert(std::tuple{sizeof(.1f16), sizeof(.1f64)}
                  == min_max<[]<class T> { return sizeof(T); }>(std::tuple{.1f16, .1f64}));

    static_assert(std::tuple{sizeof(.1f16), sizeof(.1f128)}
                  == min_max<[]<class T> { return sizeof(T); }>(std::tuple{.1f16, .1f32, .1f64, .1f128}));

    static_assert(std::tuple{sizeof(.1f32), sizeof(.1f128)}
                  == min_max<[]<class T> { return sizeof(T); }>(std::tuple{.1f128, .1f32, .1f32, .1f64}));

    return 0;
}
