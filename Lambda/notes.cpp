/*****************************************************************//**
 * \file   notes.cpp
 * \brief  Notes on lambda expression in C++ 11 with features in C++20
 *
 * []() mutable throw() -> int
 * [] - capture bracket: [=] capture by value, [&] capture by reference
 * () - parameters just like being passed to normal function
 *
 * OPTIONAL:
 * mutable - allow changes with copies, not originals with [=] only
 * throw() - throw exception
 * -> int - trailing return type // just like in Rust
 *
 * \author Xuhua Huang
 * \date   March 2021
 *********************************************************************/

#include <iostream>
#include <vector>
#include <algorithm>
#include <functional>

// lambda expression with function pointer
void ForEach(const std::vector<int>& values, void(*func)(int))
{
    /**
     * void(*function)(int)
     * void - return type of function "func"
     * func - name of passed function pointer
     * (*func) - dereference to function instead of pointer
     * (int) - argument type of "func"
     *
     * \param values
     * \param function
     */
    for (int value : values) {
        func(value);
    }
    return;
}

int main(void)
{
    std::vector<int> values = { 1, 2, 3, 4, 5 };

    // lambda
    // call function ForEach(vector, void(*)()) with lambda expression
    // lambda is essentially a throw-away function that's only used once
    ForEach(values,
        // lambda expression begins
        [](int value) {
            std::cout << "Value: " << value << "\n";
        } // end of lambda expression
    );

    std::cout << "\nSorting with lambda expression" << "\n";
    sort(values.begin(), values.end(),
        // lambda expression begins
        [&values](const int left, const int right) {
            return (left > right); // descending order
        } // end of lambda expression
    );
    std::cout << "Sorted. Printing items in \"vector<int> values\"" << "\n";

    for (const auto& item : values)
        std::cout << "Item: " << item << "\n";

    int m = 0;
    int n = 0;

    // lambda captures variable m by reference and n by value
    // parameter list: int a = 4
    // mutable keyword grants access to modify variable n
    // -> trailing return type: -> void
    [&m, n](int a) mutable -> void {
        std::cout << "\nInside of lambda"
            << "\nBefore operation: m = " << m << ", n = " << n << ", a = " << a << "\n";
        m = ++n + a;  // perform operation
        std::cout << "After operation: m = " << m << ", n = " << n << ", a = " << a << "\n";
    }(4); // 4 is assigned to int a
    // "int a" went out of scope, thus it is no longer valid

    std::cout << "\nOutside of lambda: m = " << m << ", n = " << n << "\n";

    return 0;
}
