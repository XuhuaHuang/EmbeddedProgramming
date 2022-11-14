/*****************************************************************//**
 * \file   flying_bird.cpp
 * \brief  g++ -c flying_bird.cpp -o flying_bird.exe
 * ./flying_bird.exe
 *
 * \author Xuhua Huang
 * \date   November 14, 2020
 *********************************************************************/

#include <iostream>
#include <windows.h>

int main(void)
{
    for (int fly = 0; fly < 10; fly++)
    {
        std::cout << "v^  ";
        Sleep(500);
        std::cout << "-^  ";
        Sleep(500);
    }

    return 0;
}
