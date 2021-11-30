/**
 * @file demo_constexpr.cpp
 * @author Xuhua Huang (xuhuahuang0412@gmail.com)
 * @brief Demonstration of constant expression (constants at run-time) in C++11.
 * @version 1.0
 * @date 2021-11-30
 * 
 * Constraints of constant expression on functions:
 * 1. add `constexpr` in front of the function return type.
 * 2. function body only has one valid return statement (can not return void).
 * 3. Function must be defined before being used.
 * 4. returned value must be a constant expression. 
 * 
 * To compile and run this file on Windows:
 * $ g++ -o demo_constexpr.exe .\demo_constexpr.cpp -std=c++11
 * $ .\demo_constexpr
 * 
 * @copyright Copyright (c) 2021
 * 
 */

#include <iostream>
#include <stdlib.h>

/**
 * @brief Get the const integer of value 1
 * Evaluation of function get_const() happens at compile-time
 * @return constexpr int 
 */
constexpr int get_const(void) {
    return 1;
}

/**
 * @brief use cases of constexpr int get_const() function.
 * array indes, switch statement and anonymous enum.
 * Without the `constexpr` keyword in front of the get_const() signature,
 * this function will not compile.
 * @param const int arg (to be used in switch statement) 
 */
void demo_constexpr(const int arg) {
    int arr[get_const()] = { 0 };
    /* sizeof(arr)/sizeof(arr[0]) gives the right count of elements. */
    for (int i = 0; i < sizeof(arr)/sizeof(arr[0]); ++i) {
        printf("%d, ", arr[i]);
    }
    printf("\n");
    
    enum { e1 = get_const(), e2 };
    printf("enum::e1 = %d, e2 = %d\n", e1, e2);

    switch (arg) {
        case get_const():
            printf("demo_constexpr(1); `case get_const()` invoked.\n");
            break;
        default:
            printf("Other cases; constexpr int get_const() not invoked.\n");
            break;
    }
    return;
}

int main(void) {
    int temp_const = get_const();
    std::cout << "Value of temp_const: " << temp_const << std::endl;

    demo_constexpr(1);
    demo_constexpr(2);

    system("pause");
    return 0;
}