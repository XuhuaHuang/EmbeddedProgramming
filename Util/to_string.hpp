/**
 * @file to_string.hpp
 * @author Xuhua Huang
 * @brief
 * @version 0.1
 * @date 2023-03-29
 *
 * @copyright ueg (c) 2023
 *
 */

#ifndef _TYPE_TRAITS_
#include <type_traits>
#endif // !_TYPE_TRAITS_

namespace util
{
namespace type
{

// clang-format off
template<stdext::fixed_string Str>
static auto to_string = []<auto... Ns>(std::index_sequence<Ns...>) {
    return string<Str.data[Ns]...>{};
}(std::make_index_sequence<Str.size()>{});
// clang-format on

static_assert(string<'f', 'o', 'o'> == to_string<"foo">);

} // namespace type
} // namespace util
