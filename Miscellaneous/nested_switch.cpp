// clang-format off
/*****************************************************************//**
 * \file   nested_switch.cpp
 * \brief  g++ nested_switch.cpp -o nested_switch.exe
 * ./nested_switch.exe
 * 
 * \author Xuhua Huang
 * \date   November 06, 2020
 *********************************************************************/
// clang-format on

#include <iostream>

int main(void)
{
    int x = 1, y = 1;
    std::cout << "Initially, X is: " << x << "\n"
              << "Y is: " << y << "\n";
    int m, n;
    m = n = 1;

    switch (m)
    {
    case 0: // this case is ignored
        x = x * 2;

    case 1: // executed
    {
        switch (n)
        {
        case 1: // executed
            x = x * 2;

        case 2:
            y = y * 2; // executed
            break;

        case 3:
            x++;
        }
    }
    case 2: // no break on previous case, executed
        x++;
        y++;

    case 3: // no break in previous case, executed
        x *= 2;
        y *= 2;
        break;

    default:
        x++;
        y++;
    }
    std::cout << "\nX is now: " << x << "\n"
              << "Y is now: " << y << "\n";

    return 0;
}
