/*****************************************************************//**
 * \file   BitwiseOperator.cpp
 * \brief  Notes on << and >> operator
 *
 * \author Xuhua Huang
 * \date   March 2021
 *********************************************************************/

#include <iostream>

void print(const int& value)
{
    std::cout << value << std::endl;
}

int main(void)
{
    unsigned int a = 5;
    // Debug -> Windows -> Memory -> Memory1
    // OR Ctrl + Alt+ M, 1
    // Address bar: &a + Enter -> 0x0000001444DFFB54

    print(a << 2);
    print(a >> 2);
    print((a >> 2) & 1);
    return 0;
}