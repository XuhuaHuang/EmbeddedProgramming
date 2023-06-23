/**
 * @file design_by_introspection_compiler_insights.hpp
 * @author Xuhua Huang
 * @brief This file demonstrats a typical generated/optimized file
 * from a clang-based compiler
 *
 * @version 0.1
 * @date 2023-03-29
 *
 * @copyright Copyright (c) 2023
 *
 */

consteval decltype(auto) foo(auto t) {
  if constexpr (requires{ t.foo; }) {
    return t.foo;
  } else {
    return 0;
  }
}

template<>
inline consteval int foo<__anon_14_11>(__anon_14_11 t)
{
  if constexpr(true) {
    return t.foo;
  }
}


template<>
inline consteval int foo<__anon_17_11>(__anon_17_11 t)
{
  if constexpr(false) {
  } else /* constexpr */ {
    return 0;
  }
}


constexpr struct __anon_14_11  /* size: 4, align: 4 */
{
  int foo{42};                    /* offset: 0, size: 4 */
  // inline constexpr __anon_14_11() noexcept = default;
  // inline constexpr __anon_14_11(const __anon_14_11 &) noexcept = default;
};

constexpr const __anon_14_11 f = __anon_14_11();

/* PASSED: static_assert(42 == foo(__anon_14_11(f))); */


constexpr struct __anon_17_11  /* size: 4, align: 4 */
{
  int bar{42};                    /* offset: 0, size: 4 */
  // inline constexpr __anon_17_11() noexcept = default;
  // inline constexpr __anon_17_11(const __anon_17_11 &) noexcept = default;
};

constexpr const __anon_17_11 b = __anon_17_11();

/* PASSED: static_assert(0 == foo(__anon_17_11(b))); */
