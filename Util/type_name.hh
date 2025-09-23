/**
 * @file type_name.hh
 * @author Xuhua Huang
 * @brief
 * @version 0.1
 * @date 2025-09-23
 *
 * @copyright Copyright (c) 2025
 *
 */

#ifndef TYPE_NAME_HH
#define TYPE_NAME_HH

#include <string_view>

namespace util {
namespace type {

template <typename T> constexpr std::string_view type_name() {
#if defined(__clang__)
  std::string_view p = __PRETTY_FUNCTION__;
  return p.substr(p.find('=') + 2, p.rfind(']') - p.find('=') - 2);
#elif defined(__GNUC__)
  std::string_view p = __PRETTY_FUNCTION__;
  return p.substr(p.find('=') + 2, p.rfind(']') - p.find('=') - 2);
#elif defined(_MSC_VER)
  std::string_view p = __FUNCSIG__;
  auto start = p.find("type_name<") + 10;
  auto end = p.find(">(void)");
  return p.substr(start, end - start);
#else
#error "Unsupported compiler"
#endif
}

} // namespace type
} // namespace util

#endif //! TYPE_NAME_HH
