/**
 * @file to_tuple.hpp
 * @author Xuhua Huang
 * @brief
 * @version 0.1
 * @date 2023-03-29
 *
 * @copyright ueg (c) 2023
 *
 */

namespace util
{
namespace type
{

template<typename T>
constexpr decltype(auto) to_tuple(const T& obj)
{
    constexpr std::size_t size = std::tuple_size_v<decltype(obj)>;
    return to_tuple_impl(obj, std::make_index_sequence<size>{});
}

template<typename T, std::size_t... Is>
constexpr decltype(auto) to_tuple_impl(const T& obj, std::index_sequence<Is...>)
{
    return std::make_tuple(obj.template get<Is>()...);
}

template<typename T>
[[nodiscard]] constexpr auto to_tuple_(T&& obj)
{
    if constexpr (requires { [&obj] { auto&& [p1, p2] = obj; }; })
    {
        auto&& [p1, p2] = std::forward<T>(obj);
        return std::make_tuple(p1, p2);
    }
    else if constexpr (requires { [&obj] { auto&& [p1] = obj; }; })
    {
        auto&& [p1] = std::forward<T>(obj);
        return std::tuple{p1};
    }
    else
    {
        return std::tuple{};
    }
};

} // namespace type
} // namespace util
