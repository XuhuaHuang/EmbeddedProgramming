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

