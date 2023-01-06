/*****************************************************************//**
 * \file   valarray.cpp
 * \brief  
 * 
 * \author Xuhua Huang
 * \date   December 31, 2022
 *********************************************************************/

#include <iostream>
#include <valarray>
#include <cmath>

template<typename T>
inline void print_valarray(const std::valarray<T>& arr) {
    for (const T elem : arr) {
        std::cout << elem << ", ";
    }
    std::cout << "\n";
    return;
}

auto main() -> int {
    std::valarray<double> array1{ 1.0, 2.0, 3.0, 4.0, 5.0 };
    std::valarray<double> array2{ 5.0, 4.0, 3.0, 2.0, 1.0 };

    // element-wise addition
    std::valarray<double> sum = array1 + array2;
    std::cout << "Sum: ";
    print_valarray(sum);

    // element-wise subtraction
    std::valarray<double> difference = array1 - array2;
    std::cout << "Difference: ";
    print_valarray(difference);

    // element-wise multiplication
    std::valarray<double> product = array1 * array2;
    std::cout << "Product: ";
    print_valarray(product);

    // element-wise division
    std::valarray<double> quotient = array1 / array2;
    std::cout << "Quotient: ";
    print_valarray(quotient);

    // sine function
    std::valarray<double> sin_arr = sin(array1);
    std::cout << "Sine: ";
    print_valarray(sin_arr);

    system("pause");
    return EXIT_SUCCESS;
}
