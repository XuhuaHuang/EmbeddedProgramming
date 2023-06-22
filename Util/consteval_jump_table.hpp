#ifndef CONSTEVAL_JUMP_TABLE_HPP
#define CONSTEVAL_JUMP_TABLE_HPP

#include <array>
#include <type_traits>

namespace util
{
namespace data_structure
{

template<auto N>
constexpr auto passive_fn()
{
    return N;
}

template<auto N>
constexpr auto dispatch(auto n) -> int
{
    using return_type     = std::invoke_result<decltype(&passive_fn<0>)>::type;

    const auto jump_table = []<auto... I>(std::index_sequence<I...>) {
        return std::array<return_type, sizeof...(I)>{(passive_fn<I>())...};
    }(std::make_index_sequence<N>{});
    return jump_table[n];
};

} // namespace data_structure
} // namespace util

#endif // !CONSTEVAL_JUMP_TABLE_HPP
