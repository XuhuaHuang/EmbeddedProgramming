# **Embedded Programming**

$$\int_b^d study \,dt= life$$

https://g.dev/xuhua-huang-io

<https://github.com/XuhuaHuang/EmbeddedProgramming>

`#include <❤>`

<!-- Link Definitions for Wakatime -->
[Wakatime Logo Link]: https://wakatime.com/badge/user/f89598ea-6723-481b-a51b-6323e54a3c5c/project/0645c716-822f-4ba1-a897-04cf5a3fbbfb.svg
[Wakatime Info Link]: https://wakatime.com/badge/user/f89598ea-6723-481b-a51b-6323e54a3c5c/project/0645c716-822f-4ba1-a897-04cf5a3fbbfb?style=flat

[![wakatime][Wakatime Logo Link]][Wakatime Info Link]

This repository _hopefully_ can lead you through the **modern C++** world, with some of its popular tool chains. <br>
Each topic is placed in individual folder. Projects are placed under each descriptively-named folders. <br>
**Most** of the directories are provided with a `CMakeLists.txt`. <br>
Using `CMake` will be significantly easier than manually compiling all the files with your favorite compiler. <br>
For your comfort, some of the files have required compilation command documented in the source file itself.

## Table of Contents

- [**Embedded Programming**](#embedded-programming)
  - [Table of Contents](#table-of-contents)
  - [**Special Thanks** ❤](#special-thanks-)
  - [Languages](#languages)
  - [**Getting Started**](#getting-started)
  - [**Repository Directories**](#repository-directories)
    - [`Util`](#util)
    - [`HackerRank`](#hackerrank)
    - [`LeetCodePlayground`](#leetcodeplayground)
    - [`ObjectiveC`](#objectivec)
    - [`Projects`](#projects)
  - [References](#references)
    - [**Commonly Used Command in `CMake`**](#commonly-used-command-in-cmake)

## **Special Thanks** ❤

**Prof. Charmaine Jirgens** <br>
My mentor to the programming world <br>
Professor, Electronics Engineering and Information Technology <br>
Heritage College, Gatineau, Quebec, Canada

> Software does not run in a magic fairy aether powered by the fevered dreams of CS PhDs.

## Languages

**C/C++, Objective-C/C++**

<img src="Settings/images/c_logo.png" alt="An image for C Language" width="100"/><img src="Settings/images/cpp_logo.png" alt="An image for C++" width="100"/>   <img src="Settings/images/mingw_logo.png" alt="An image for MinGW" width="110"/>

```C++
class person
{
public:
    explicit person() = default;

    explicit person(const std::string& fn, const std::string& ln)
        : first(fn)
        , last(ln)
    {
    }

    explicit person(std::string&& fn, std::string&& ln)
        : first(std::move(fn))
        , last(std::move(ln))
    {
    }

    person(const person& rhs)                = default;
    person& operator=(const person&)         = default;

    person(person&& rhs) noexcept            = default;
    person& operator=(person&& rhs) noexcept = default;

    virtual ~person() noexcept               = default;

    [[nodiscard]] inline std::string& first_name() { return first; }
    inline const std::string&         first_name() const { return first; }

    [[nodiscard]] inline std::string& last_name() { return last; }
    inline const std::string&         last_name() const { return last; }

private:
    std::string first;
    std::string last;
};

template<typename T>
concept printable = requires(T t) {
    { std::cout << t } -> std::convertible_to<std::ostream&>;
}

struct print
{
    constexpr print() = default;

    template <typename T>
        requires printable<T>
    inline constexpr void operator()(T const& t) const
    {
        std::cout << t << "\n";
    }
};
```

## **Getting Started**

**Example to Compile a File Named `get_tie.cpp`**

```Bash
g++ --version
cd ./StandardTemplateLibrary/Tuple
g++ -g -Wall -Wextra -Wpedantic -c get_tie.cpp -o get_tie.exe -std=gnu++2b
./get_tie
```

**To Update `MinGW` on Windows** <br>
Run a `PowerShell` session with administrator privilege and run:

```Bash
# Get the latest version of mingw
mingw-get update
mingw-get upgrade
# Verify the version of installed gcc and g++
gcc --version
g++ --version
```

## **Repository Directories**

If you already have a configured `CMake` for your operating system, simple change to the directory with such `CMakeLists.txt` and run:<br>

```Bash
cmake .
```

or

```Bash
cmake ./CMakeLists.txt
```

For example, change to directory `./DesignPatterns`:

```Bash
cd ./DesignPatterns
cmake ./CMakeLists.txt
```

The convention is to create a folder dedicated to `CMake` files, for example, `build` or `bin`:

```Bash
cd ./DesignPatterns
mkdir build
cd build
cmake ../CMakeLists.txt -G "Visual Studio 17 2022"
```

To build with popular `Ninja` or `MinGW` generator:

```Bash
# With Ninja generator
cmake ../CMakeLists.txt -G "Ninja"
# With MinGW generator
cmake ../CMakeLists.txt -G "MinGW Makefiles"
```

### `Util`

Functionality provided by separate module. A namespace `util` is created to better manage the functions.<br>
Tests and `GoogleTest` are located within the `Util/tests` folder.

```C++
namespace util {
    namespace data_structure {}
    namespace iife {}
    namespace list {}
    namespace math {
        namespace cartesian_plane {}
        namespace euclidean_space {}
    }
    namespace parse {}
    namespace physics {}
    namespace pointer {}
    namespace range {}
    namespace type {}
    namespace type_safety {}
    namespace vector {}
}
```

Contains template (generic) function in a C-style header file, providing the following functionality:

- `is_instance_of.hpp`
  - [definition](./util/is_instance_of.hpp)
  - [unit tests](./Util/tests/test_is_instance_of.cpp)
  - identify whether an object if of a specified type.
  - comparable to `isinstance()` in Python.
- `is_same_type_of.hpp`
  - [definition](./Util/is_same_type.hpp)
  - identify whether two objects are the same type.
  - use `typeid().hash_code()` and `typeid().name()`.
- `log.h`
  - [definition](./Util/log.h)
  - function-style definition `LOG(...)` using macro in C.
- `parse.hpp`
  - [definition](./Util/parse.hpp)
  - [unit tests](./Util/tests/test_parse_str.cpp)
  - easily split a comma-separated `std::string`.
- `print_list.hpp`
  - [definition](./Util/print_list.hpp)
  - template function to print a `std::list<>` to console.
  - accepts a generic type of `std::list<>`.
- `print_range.hpp`
  - [definition](./Util/print_range.hpp)
  - [unit tests](./Util/tests/test_print_range.cpp)
  - template function to print a `std::ranges<>` to console.
  - accepts a generic type of `std::ranges<>`.
- `print_vec.hpp`
  - [definition](./Util/print_vec.hpp)
  - template function to print a `std::vector<>` to console.
  - accepts a generic type of `std::vector<>`.
- `safe_free.hpp`
  - [definition](./Util/safe_free.hpp)
  - [unit tests](./Util/tests/test_safe_free.cpp)
  - `free()` function implementation to release allocated resources.
- `trimstr.hpp`
  - [definition](./Util/trimstr.hpp)
  - [unit tests](./Util/tests/gtest_trim_str.cpp)
  - trim a `std::string` using pipeline operator and `std::ranges::to<>`.

### `HackerRank`

Contains solutions to some of the basic problem solving coding questions. Provided file name most likely describes the content.
The `README.md` has more handy notes when encountering those problems.  
[Click to see my HackerRank profile](https://www.hackerrank.com/XuhuaHuang?hr_r=1)

### `LeetCodePlayground`

Contains solutions to some of the basic problem solving coding questions.  
[Click to see my LeetCode profile](https://leetcode.com/XuhuaHuang/)

### `ObjectiveC`

Popular concepts in Objective-C.
Compiled in Windows using `GNUstep Core` and provided `GNUstep` developer tools.

### `Projects`

Contains projects carried along the coursework and includes some personal project as well.
For example, building a terminal progress bar for visual effects and working with `OpenGL` library in `C++`.

## References

### **Commonly Used Command in `CMake`**

- [`cmake-generator-expressions`](https://cmake.org/cmake/help/latest/manual/cmake-generator-expressions.7.html)
- [`target_sources`](https://cmake.org/cmake/help/latest/command/target_sources.html)
- [`target_compile_options`](https://cmake.org/cmake/help/latest/command/target_compile_options.html)
- [`target_compile_definitions`](https://cmake.org/cmake/help/latest/command/target_compile_definitions.html)
- [`target_include_directories`](https://cmake.org/cmake/help/latest/command/target_include_directories.html)
- [`target_link_libraries`](https://cmake.org/cmake/help/latest/command/target_link_libraries.html)
