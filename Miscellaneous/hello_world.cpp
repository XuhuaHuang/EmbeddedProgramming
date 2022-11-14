/*****************************************************************//**
 * \file   hello_world.cpp
 * \brief  g++ -c hello_world.cpp -o hello_world.exe
 * ./hello_world.exe
 *
 * \author Xuhua Huang
 * \date   November 14, 2020
 *********************************************************************/

#include <windows.h>
#include <iostream>
#include <string>

int main(void)
{
    std::string greeting = "Hello, world!";

    for (int iter = 0; iter < greeting.length(); iter++)
    {
        std::cout << greeting[iter];
        Sleep(500);
    }

    std::cout << " "; // an extra space to accommodate with the following for loop
    Sleep(1500);

    for (int iter2 = 0; iter2 < greeting.length(); iter2++)
    {
        std::cout << "\b\b ";
        //greeting.replace(iter2, 1, " ");
        Sleep(500);
    }

    return 0;
}
