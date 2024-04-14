// cl .\use_std_invoke_r.cpp /W4 /Zc:__cplusplus /EHsc /std:c++latest /experimental:module
// .\use_std_invoke_r.exe

#include <functional>
#include <type_traits>
#include <typeinfo>

constexpr auto sum(auto... ts)
{
    return (ts + ...);
}

[[nodiscard]] constexpr auto call(auto... ts)
{
    using T = typename std::common_type_t<decltype(ts)...>;
    return std::invoke_r<T>(sum<decltype(ts)...>, ts...);
}

int main()
{
    static_assert(6 == call(1, 2, 3));
    static_assert(typeid(int) == typeid(call(1, 2, 3)));

    static_assert(6u == call(1u, 2u, 3u));
    static_assert(typeid(unsigned) == typeid(call(1u, 2u, 3u)));

    static_assert(6u == call(1, 2u, 3l));
    // static_assert(typeid(long) == typeid(call(1, 2u, 3l)));

    static_assert(6u == call(1ll, 2ull, 3l));
    static_assert(typeid(unsigned long long) == typeid(call(1ll, 2ull, 3l)));

    return 0;
}
