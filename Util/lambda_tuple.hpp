#ifndef LAMBDA_TUPLE_HPP
#define LAMBDA_TUPLE_HPP

#include <type_traits>
#include <utility>

namespace util
{
namespace type
{

// clang-format off
constexpr auto tuple = [] [[nodiscard]] (auto... args) {
    return [=] [[nodiscard]] (auto fn) { return fn(args...); };
};
// clang-format on

template<::std::size_t N, class... Args>
struct nth_type;

template<class T, class... Args>
struct nth_type<0, T, Args...> : ::std::type_identity<T>
{
};

template<::std::size_t N, class T, class... Args>
struct nth_type<N, T, Args...> : nth_type<N - 1, Args...>
{
};

template<auto N>
[[nodiscard]] constexpr auto get(auto t)
{
    auto func = []<class... Args>(Args... args) {
        typename nth_type<N, Args...>::type result;

        auto impl = [Count = 0](auto input, auto& result) mutable {
            if (Count == N)
            {
                result = input;
            }
            ++Count;
        };

        (impl(args, result), ...);

        return result;
    };

    return t(func);
}

template<class T>
[[nodiscard]] constexpr auto get(auto t)
{
    auto func = []<class... Args>(Args... args) {
        T result;

        auto impl = [has_val = false]<class Arg>(Arg input, auto& result) mutable {
            if (::std::is_same_v<T, Arg> && not has_val)
            {
                result  = input;
                has_val = true;
            }
        };

        (impl(args, result), ...);

        return result;
    };

    return t(func);
}

} // namespace type
} // namespace util

#endif // !LAMBDA_TUPLE_HPP
