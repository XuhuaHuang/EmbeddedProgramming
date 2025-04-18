// clang-format off
/*****************************************************************//**
 * \file   example.cpp
 * \brief  Example application to verify libtorch is linked properly
 * and CMake is also well configured.
 * 
 * \author Xuhua Huang
 * \date   November 10, 2023
 *********************************************************************/
// clang-format on

#include <torch/torch.h>

#include <iostream>

int main() {
    const torch::Tensor tensor = torch::rand({2, 3});
    std::cout << tensor << "\n";

    // using externally created data
    float               data[] = {1, 2, 3, 4, 5, 6};
    const torch::Tensor f      = torch::from_blob(data, {2, 3});
    std::cout << f << "\n";
    std::cout << __LINE__ << " size of f: " << sizeof(f) << "\n";

    // access tensor elements with a 2-dimensional accessor that holds floats.
    at::TensorAccessor accessor = tensor.accessor<float, 2>();
    float              trace    = 0.f;
    for (int i = 0; i < accessor.size(0); i++) {
        // use the accessor to get tensor data.
        trace += accessor[i][i];
    }
    std::cout << __LINE__ << " trace: " << trace << "\n";

    return 0;
}
