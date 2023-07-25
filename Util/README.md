# `Util`

## About

Contains template (generic) function in a C-style header file, providing the following functionality:

- `is_instance_of.hpp`
  - [definition](./is_instance_of.hpp)
  - [unit tests](./tests/test_is_instance_of.cpp)
  - identify whether an object if of a specified type.
  - comparable to `isinstance()` in Python.
- `is_same_type_of.hpp`
  - [definition](./is_same_type.hpp)
  - identify whether two objects are the same type.
  - use `typeid().hash_code()` and `typeid().name()`.
- `log.h`
  - [definition](./log.h)
  - function-style definition `LOG(...)` using macro in C.
- `parse.hpp`
  - [definition](./parse.hpp)
  - [unit tests](./tests/test_parse_str.cpp)
  - easily split a comma-separated `std::string`.
- `print_list.hpp`
  - [definition](./print_list.hpp)
  - template function to print a `std::list<>` to console.
  - accepts a generic type of `std::list<>`.
- `print_range.hpp`
  - [definition](./print_range.hpp)
  - [unit tests](./tests/test_print_range.cpp)
  - template function to print a `std::ranges<>` to console.
  - accepts a generic type of `std::ranges<>`.
- `print_vec.hpp`
  - [definition](./print_vec.hpp)
  - template function to print a `std::vector<>` to console.
  - accepts a generic type of `std::vector<>`.
- `safe_free.hpp`
  - [definition](./safe_free.hpp)
  - [unit tests](./tests/test_safe_free.cpp)
  - `free()` function implementation to release allocated resources.
- `trimstr.hpp`
  - [definition](./trimstr.hpp)
  - [unit tests](./tests/gtest_trim_str.cpp)
  - trim a `std::string` using pipeline operator and `std::ranges::to<>`.

## `cpp` Language Reference and Notes

### `&` and `&&` overload operators thoughts experiment - **Reference Qualifiers**

- Consider the `&` and `&&` operator overloads either with const qualifications or not as "invoked with"
  - For example, `&concrete_instance` shall be considered as "such function is invoked with a lvalue"  
    Consider the following example: <https://github.com/XuhuaHuang/EmbeddedProgramming/blob/main/MemberFnAmpersand/MemberFnAmpersand.cpp>
    - The function with the signature `int& getArg()&` is _invoked with_ a mutable lvalue (left value)
    - The function with the signature `int& getArg()&&` is _invoked with_ a mutable rvalue (right value)
  - Such mentality will also make sense for a normal operation like the following;
    - `int* p_int = &int_on_stack;`  
      In this case, the `&` operator is "invoked with" a lvalue
    - `std::string str = std::move(another_std_str);`  
      In this case, `std::move(std::string&& src)` is "invoked with" a (pure) rvalue

### Arithmetic and Comparison Operators Support

```cpp
template<typename Type>
struct support_stdspan_arithmetic_operators {
    using value_type = std::remove_cv_t<Type>;
public:
    inline constexpr friend std::span<value_type> operator + (std::span<value_type> lhs, const value_type n)
    {
        std::span<value_type> copy{ lhs };
        for (/* std::span<value_type>::iterator */ constexpr auto it = copy.begin(); it != copy.end(); it++) {
            *it += n;
        }
        return std::span<value_type>(copy);
    }
};

struct long_double_span_arithmetic_operators : support_stdspan_arithmetic_operators<long double> {};

struct double_span_arithmetic_operators : support_stdspan_arithmetic_operators<double> {};

template<typename Type>
struct support_stdspan_comparison_operators {
    using value_type = std::remove_cv_t<Type>;
public:
    constexpr support_stdspan_comparison_operators() = default;
    template<typename value_type>
    friend constexpr bool operator == (std::span<value_type> lhs, std::span<value_type> rhs) { return true; }
};

struct double_span_comparison_operator : support_stdspan_comparison_operators<double> {};
```

### Include Gard

```cpp
#if defined(__has_include) && __has_include(<version>)
#include <version>
#endif
```

### Design by Introspection

```cpp
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
```

### Immediately-Invoked Function Expression (IIFE)

```cpp
#include <iostream>
#include "unroll.hpp"

int main(void) {
    util::iife::unroll<2>([]{ std::puts("Hello C++ 20!"); });
    return 0;
}
```

### `std::valarray::swap` and `std::addressof` Implementation

```cpp
void swap(valarray& _Right) noexcept {
    if (this != _STD addressof(_Right)) {
        _STD swap(_Myptr, _Right._Myptr);
        _STD swap(_Mysize, _Right._Mysize);
    }
}

_EXPORT_STD template <class _Ty>
_NODISCARD constexpr _Ty* addressof(_Ty& _Val) noexcept {
    return __builtin_addressof(_Val);
}

_EXPORT_STD template <class _Ty>
const _Ty* addressof(const _Ty&&) = delete;
```

