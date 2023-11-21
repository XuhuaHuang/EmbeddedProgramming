/*****************************************************************//**
 * \file   example.cpp
 * \brief  Example application to verify libtorch is linked properly
 * and CMake is also well configured.
 * 
 * \author Xuhua Huang
 * \date   November 10, 2023
 *********************************************************************/

#include <iostream>
#include <torch/torch.h>

int main()
{
    torch::Tensor tensor = torch::rand({2, 3});
    std::cout << tensor << "\n";

    return 0;
}
