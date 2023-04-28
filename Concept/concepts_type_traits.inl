#pragma once

#include <concepts>
#include <type_traits>

namespace util
{
namespace type
{

template<typename T>
concept StandardLayout = std::is_standard_layout_v<T>;

template<typename T>
concept NotStandardLayout = not StandardLayout<T>;

} // namespace type
} // namespace util
