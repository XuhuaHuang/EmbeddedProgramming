/**
 * @file is_array.cpp
 * @author Xuhua Huang
 * @brief
 * @version 0.1
 * @date 2023-03-27
 *
 * cl .\is_array.cpp /std:c++latest /EHsc
 * .\is_array.exe
 *
 * @copyright ueg (c) 2023
 *
 */

#include <iostream>
#include <type_traits>

template<typename T>
void print_array_info(const T& arr)
{
    // std::is_array<T>::value
    // std::is_array_v<T>
    if constexpr (std::is_array_v<T>)
    {
        std::cout << "Array of size " << std::extent_v<T> << "\n";
    }
    else
    {
        std::cout << "Not an array" << "\n";
    }
}

int main()
{
    int arr[5]  = {1, 2, 3, 4, 5};
    int not_arr = 5;

    print_array_info(arr);     // Array of size 5
    print_array_info(not_arr); // Not an array

    return 0;
}
