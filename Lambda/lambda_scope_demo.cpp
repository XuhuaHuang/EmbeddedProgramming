/**
 * @file lambda_scope_demo.cpp
 * @author Xuhua Huang
 * @brief Capture by value and capture by reference demonstration
 * @version 0.1
 * @date 2022-01-06
 * 
 * To compile and run:
 * $ g++ -o lambda_scope_demo.exe .\lambda_scope_demo.cpp -std=c++11
 * ./lambda_scope_demo
 * 
 * @copyright Copyright (c) 2022
 * 
 */

#include <iostream>
#include <stdlib.h>
#include <functional>

int main(void) {
    int x = 5, y = 10;

    std::cout << "Outside the lambda:" << "\n"
        << "Address of x in lambda: " << &x << ", value of x: " << x << "\n"
        << "Address of y in lambda: " << &y << ", value of y: " << y << "\n" << "\n";

    auto test_lambda_capture = [x, &y]() mutable -> void {
        std::cout << "Inside the lambda:" << "\n"
            << "Address of x in lambda: " << &x << ", value of x: " << x << "\n"
            << "Address of y in lambda: " << &y << ", value of y: " << y << "\n";

        x += 1;
        y += 2;

        std::cout << "x: " << x << ", y: " << y << "\n" << "Exit lambda" << "\n" << "\n";
    };

    test_lambda_capture();
    /**
     * @brief First call to the function object
     * member x is now 6, member y is now 12
     */

    /* Change the value of x and y. */
    x = 10;
    y = 20;

    test_lambda_capture(); // 7, 22
    /**
     * @brief Second call to the function object
     * &y constantly refers to the `int y` in main() scope
     * That's why value of y is changed; the run-time environment needs ro re-refer to y.
     * member x is a copy inside the function object, change in x in the main() does nto affect the member.
     */

    system("pause");
    return 0;
}