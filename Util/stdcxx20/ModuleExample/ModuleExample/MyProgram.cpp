/*****************************************************************//**
 * \file   MyProgram.cpp
 * \brief  Demonstration to import a C++20 module from a interface file
 * 
 * \author Xuhua Huang (xuhua.huang.io@outloook.com)
 * \date   September 2022
 *********************************************************************/

// The import declaration can appear only at global scope
import Example;
//import std.core;
#include <iostream>

int main(void)
{
    std::cout << "The result of fn() is " << Example_NS::fn() << "\n"; // 42
    return 0;
}
