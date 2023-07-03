/**
 * @file design_by_introspection.hpp
 * @author Xuhua Huang
 * @brief 
 * @version 0.1
 * @date 2023-03-29
 * 
 * @copyright ueg (c) 2023
 * 
 */

// clang-format off
consteval decltype(auto) foo(auto t) {
    if constexpr (requires{ t.foo; }) {
        return t.foo;
    } else {
        return 0;
    }
}

constexpr struct { int foo{42}; } f;
static_assert(42 == foo(f));

constexpr struct { int bar{42}; } b;
static_assert(0 == foo(b));

// clang-format on
