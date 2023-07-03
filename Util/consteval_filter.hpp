#ifndef CONSTEVAL_FILTER_HPP
#define CONSTEVAL_FILTER_HPP

#include <array>
#include <tuple>
#include <utility>
#include <vector>

namespace util
{
namespace range
{

constexpr auto filter(auto t, auto fn)
{
    // get the vector of filtered elements
    constexpr auto r = [=] {
        return std::apply(
            [=](auto... ts) {
                return [=] {
                    auto v = std::vector{ts...};
                    std::erase_if(v, std::not_fn(fn));
                    return v;
                };
            },
            t());
    }();

    // convert the vector to a tuple
    return [=]<auto... Ns>(std::index_sequence<Ns...>) {
        const auto v = r();
        return std::tuple{v[Ns]...};
    }(std::make_index_sequence<r().size()>{});
}

} // namespace range
} // namespace util

#endif // !CONSTEVAL_FILTER_HPP
