/**
 * @file auto.cpp
 * @author Xuhua Huang
 * @brief Demonstration of a macro - compiler version dependant 
 * @version 0.1
 * @date 2021-11-07
 * 
 * Command to compile and run on Windows:
 * $ g++ -o auto.exe .\auto.cpp -std=c++11
 * $ .\auto
 * 
 * @copyright Copyright (c) 2021
 * 
 */

#include <iostream>
#include <stdlib.h>

/**
 * @brief Theorectically, Max_cpp11 macro should be faster.
 * auto keyword would determine the type during runtime
 * prevented reading the same variable twice (Max_cpp0x)
 */
#if __cplusplus < 201103L
#define Max_cpp0x(a, b) ((a) > (b)) ? (a) : (b)
#elif __cplusplus >= 201103L
#define Max_cpp11(a, b) ({      \
    auto _a = (a);              \
    auto _b = (b);              \
    (_a > _b) ? _a : _b;        \
})
#endif

int main(void) {

    int max1 = Max_cpp0x(1*2*3*4, 5+6+7+8);
    int max2 = Max_cpp11(1*2*3*4, 5+6+7+8);

    system("pause");
    return 0;
}
