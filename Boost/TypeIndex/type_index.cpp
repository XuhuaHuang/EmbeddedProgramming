/**
 * @file type_index.cpp
 * @author Xuhua Huang
 * @brief
 * @version 0.1
 * @date 2023-03-17
 *
 * @copyright Copyright (c) 2023
 *
 */

#include <boost/type_index.hpp>
#include <iostream>

using boost::typeindex::type_id_with_cvr;
using boost::typeindex::type_index;

template<typename T>
inline constexpr bool is_same_type(const T& lhs, const T& rhs)
{
    return type_index<decltype(lhs)>() == type_index<decltype(rhs)>();
}

template<typename T>
inline void print_type(const T& value)
{
    std::cout << "Type of value " << value << " is " << type_id_with_cvr<T>().pretty_name() << "\n";
}

int main()
{
    int x = 42;
    print_type(x);
    double y = 3.14;
    print_type(y);

    std::cout << "x and x are of the same type: " << std::boolalpha << is_same_type(x, x) << "\n";
    std::cout << "x and y are of the same type: " << std::boolalpha << is_same_type(x, y) << "\n";

    const char* z = "hello";
    print_type(z);

    return 0;
}
