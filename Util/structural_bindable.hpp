
#include <concepts>
#include <utility>

template<typename T, std::size_t N>
concept has_global_get_N = requires (T t) { std::get<N>(t); };

template<typename T, std::size_t N>
concept has_member_get_N = requires (T t) { t.template get<N>(); };

template<typename T, std::size_t N>
concept has_get_N = has_global_get_N<T, N> or has_member_get_N<T, N>;

template<typename T, std::size_t N>
struct has_get_for_size : public std::false_type
{
};

template<typename T, std::size_t N>
    requires (N <= std::tuple_size_v<T> && has_get_N < T, N <= std::tuple_size_v<T> ? N - 1 : 0 >)
struct has_get_for_size<T, N>
{
    constexpr static bool value = has_get_N<T, N - 1> && has_get_for_size<T, N - 1>::value;
};

template<typename T, std::size_t N>
concept structure_bindable = (std::tuple_size_v<T> == N) && has_get_for_size<T, N>::value;

template<typename T, size_t N, typename Expected>
concept global_get_N = requires (T t) { requires std::same_as<std::decay_t<decltype(std::get<N>(t))>, Expected>; };

template<typename T, size_t N, typename Expected>
concept member_get_N = requires (T t) { requires std::same_as<std::decay_t<decltype(t.template get<N>())>, Expected>; };

template<typename T, size_t N, typename Expected>
concept get_N = global_get_N<T, N, Expected> or member_get_N<T, N, Expected>;
