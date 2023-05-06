#include <type_traits>

template<typename T>
auto sum(const T& t)
{
    return t;
}

template<typename First, typename Second, typename... T>
auto sum(const First& first, const Second& second, const T&... t)
{
    typename std::common_type<First, T...>::type result = first;
    (void)std::initializer_list<int>{(result += t, 0)...};
    return result;
    // return first + sum(second, t...);
}
