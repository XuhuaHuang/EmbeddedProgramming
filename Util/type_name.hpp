/**
 * @file type_name.hpp
 * @author Xuhua Huang
 * @brief
 * @version 0.1
 * @date 2025-09-23
 *
 * @copyright Copyright (c) 2025
 *
 */

#pragma once
#ifndef TYPE_NAME_HPP
#define TYPE_NAME_HPP

#if __cplusplus < 201703L
#error "type_name.hpp requires C++17 or later (for std::string_view)"
#endif

#include <string>
#include <string_view>

namespace util {
namespace type {

template <typename T> constexpr auto type_name() {
  std::string_view name, prefix, suffix;
#ifdef __clang__
  name = __PRETTY_FUNCTION__;
  prefix = "auto util::type::type_name() [T = ";
  suffix = "]";
#elif defined(__GNUC__)
  name = __PRETTY_FUNCTION__;
  prefix = "constexpr auto util::type::type_name() [with T = ";
  suffix = "]";
#elif defined(_MSC_VER)
  name = __FUNCSIG__;
  prefix = "auto __cdecl util::type::type_name<";
  suffix = ">(void)";
#endif
  name.remove_prefix(prefix.size());
  name.remove_suffix(suffix.size());
  return name;
}

} // namespace type
} // namespace util

#endif //! TYPE_NAME_HH
