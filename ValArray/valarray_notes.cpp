/**
 * @file valarray_notes.cpp
 * @author Xuhua Huang
 * @brief
 * @version 0.1
 * @date 2023-03-27
 *
 * cl .\valarray_notes.cpp /std:c++latest /EHsc
 * .\valarray_notes.exe
 *
 * https://en.cppreference.com/w/cpp/numeric/valarray
 * https://en.cppreference.com/w/cpp/numeric/valarray/slice
 *
 * @copyright ueg (c) 2023
 *
 */

#include <algorithm>
#include <cassert>
#include <concepts>
#include <iostream>
#include <limits>
#include <span>
#include <type_traits>
#include <valarray>

#ifndef log
#define log std::cout << __LINE__ << ": " << std::boolalpha
#endif

template<typename T>
    requires std::is_arithmetic_v<T> && (!std::is_pointer_v<T>) && (!std::is_reference_v<T>)
inline std::ostream& operator<<(std::ostream& os, const std::valarray<T>& values) noexcept
{
    os << "[";
    if (values.size() > 1) [[likely]]
    {
        for (const T* it = std::begin(values); it < std::end(values) - 1; it++)
        {
            os << *it << ", ";
        }
        os << values[values.size() - 1];
    }
    else if (values.size() == 1)
    {
        os << values[0];
    }
    os << "]";
    return os;
}

template<>
inline std::ostream& operator<<(std::ostream& os, const std::valarray<std::uint8_t>& values) noexcept = delete;

int main()
{
    static_assert(std::is_arithmetic_v<std::uint8_t>);

    // log << std::is_arithmetic_v<std::uint8_t> << "\n";
    // log << std::numeric_limits<std::uint16_t>::min() << "\n";
    // log << std::numeric_limits<std::uint16_t>::max() << "\n";

    // create an empty valarray
    std::valarray<float_t> val;
    log << val << "\n";
    val.resize(1);
    val[0] = 3.14;
    log << val << "\n";

    val.resize(2);
    val[1] = 2.71;
    log << val << "\n";

    // create a valarray of size 5, initialized with values 0, 1, 2, 3, 4
    std::valarray<int> v{0, 1, 2, 3, 4};

    // print the elements of the valarray
    log << v << "\n";

    // apply a function to each element of the valarray
    auto f  = [](int x) { return x * x; };
    auto v2 = std::valarray<int>(v.apply(f));

    log << v2 << "\n";

    // perform mathematical operations on the valarray
    std::valarray v3 = v + v2;
    log << "v3 is of type std::valarray<int>: " << std::is_same_v<decltype(v3), std::valarray<int>> << "\n";
    log << v3 << "\n";

    auto v4 = v3.apply([](int x) { return x / 2; });
    log << "v4 is of type std::valarray<int>: " << std::is_same_v<decltype(v4), std::valarray<int>> << "\n";
    log << v4 << "\n";

    // increment the value in v
    v += 1;
    log << v << "\n";

    // compute the sum of the valarray
    int sum = v.sum();
    log << "sum of v: " << sum << "\n";

    // compute the square of each element of the valarray
    std::valarray<int> v_squared = v * v;
    log << v_squared << "\n";

    // compute the dot product of v and v_squared
    int dot_product = (v * v_squared).sum();
    log << "dot product of v and v_squared: " << dot_product << "\n";

    v = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
    log << v << "\n";

    // create a slice with start index 2, length 3, and stride 2
    // s[2] = 3
    // s[2 + 2] == s[4] = 5
    // s[2 + 2 + 2] == s[6] = 7
    std::slice s{2, 3, 2};
    log << typeid(s).name() << "\n"; // class std::slice

    // use the slice to create a new valarray
    std::valarray<int> result = v[s];
    // print the new valarray
    log << result << "\n";

    // change the value of the original valarray
    v[s] = 0;
    // print the original valarray
    log << v << "\n";

    return 0;
}
