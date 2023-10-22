# Template

## Template Type Deduction Guide

```cxx
template<typename template_arguments>
class_name(arguent_type_list)
-> class_name<template_arg_list>;
```

Consider the following tempalte class declaration:

```cxx
template<typename T>
class TPoint : public tri_dimensional;
```

The template type deduction guide would look like the following:

```cxx
// TPoint<int>
template<typename T>
TPoint(int, int, int) -> TPoint<int>;

// TPoint<std::size_t>
template<typename T>
TPoint(std::size_t, std::size_t, std::size_t) -> TPoint<std::size_t>;
```

## From Templates to Concepts

```cxx
template<typename T, bool>
struct printHelper {
    static constexpr void print(T const& t) { fmt::print("{}", t); };
};

// Create a partial template specialization for pointer types
// with the help with type traits
template<typename T>
struct printHelper<T, true> {
    static constexpr void print(T const& t) { fmt::print("{}", *t); };
};

template<typename T>
void print(T const& t) {
    printHelper<T, std::is_pointer<T>::value>::print(t);
}

template<typename T>
using add_pointer_t = typename add_pointer<T>::type;

template<typename T>
constexpr bool is_pointer_v = is_pointer<T>::value;

template<typename T>
void print(T const& t) {
    if constexpr (std::is_pointer_v<T>) {
        fmt::print("{}", *t);
    } else {
        fmt::print("{}", t);
    }
}
```
