/**
 * @file ptr32_ptr64.cpp
 * @author Xuhua Huang
 * @brief 
 * @version 0.1
 * @date 2023-01-11
 * 
 * cl .\ptr32_ptr64.cpp /Za /std:c++20
 * .\ptr32_ptr64.exe
 * 
 * @copyright Copyright (c) 2023
 * 
 */

#include <cstdlib>
#include <iostream>

int main()
{
    int* __ptr32 p32;
    int* __ptr64 p64;

    p32 = (int* __ptr32)malloc(4);
    *p32 = 32;
    std::cout << "sizeof(p32): " << sizeof(p32) << "\n";
    std::printf("Address of p32: %p\n", p32);
    std::cout << *p32 << "\n";

    p64 = (int* __ptr64)malloc(4);
    *p64 = 64;
    std::cout << "sizeof(p64): " << sizeof(p64) << "\n";
    std::printf("Address of p64: %p\n", p32);
    std::cout << *p64 << "\n";
}
