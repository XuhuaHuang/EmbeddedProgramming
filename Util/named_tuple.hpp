#ifndef NAMED_TUPLE_HPP
#define NAMED_TUPLE_HPP

#include <iostream>
#include <string_view>
#include <tuple>
#include <type_traits>

namespace util
{
namespace type
{

template<auto Size>
struct fixed_string
{
    char                  data[Size + 1]{};
    static constexpr auto size = Size;
    constexpr explicit(false) fixed_string(char const* str) { std::copy_n(str, Size + 1, data); }
    constexpr explicit(false) operator std::string_view() const { return {data, Size}; }
};

template<auto Size>
fixed_string(char const (&)[Size]) -> fixed_string<Size - 1>;

template<auto...>
struct arg
{
    template<class T>
    constexpr auto operator=(const T& t) const
    {
        return std::pair<arg, T>{*this, t};
    }
};

template<fixed_string Str>
constexpr auto operator""_t()
{
    return []<auto... Ns>(std::index_sequence<Ns...>) {
        return arg<Str.data[Ns]...>{};
    }(std::make_index_sequence<Str.size>{});
}

template<class... Ts>
struct namedtuple : std::tuple<Ts...>
{
    using std::tuple<Ts...>::tuple;

    template<class T>
    constexpr decltype(auto) operator[](const T) const
        requires (not std::is_void_v<boost::mp11::mp_map_find<boost::mp11::mp_list<Ts...>, T>>)
    {
        using type = boost::mp11::mp_map_find<boost::mp11::mp_list<Ts...>, T>;
        return std::get<type>(*this).second;
    }

    template<class T>
    constexpr auto& operator[](const T)
        requires (not std::is_void_v<boost::mp11::mp_map_find<boost::mp11::mp_list<Ts...>, T>>)
    {
        using type = boost::mp11::mp_map_find<boost::mp11::mp_list<Ts...>, T>;
        return std::get<type>(*this).second;
    }
};
template<class... Ts>
namedtuple(Ts&&...) -> namedtuple<Ts...>;

} // namespace type
} // namespace util

#endif // !NAMED_TUPLE_HPP
