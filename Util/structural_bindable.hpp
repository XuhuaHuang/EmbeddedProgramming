
#include <concepts>

template<typename T, std::size_t N>
concept has_global_get_N = requires (T t) { std::get<N>(t); };

template<typename T, std::size_t N>
concept has_member_get_N = requires (T t) { t.template get<N>(); };

template<typename T, std::size_t N>
concept has_get_N = has_global_get_N<T, N> or has_member_get_N<T, N>;
