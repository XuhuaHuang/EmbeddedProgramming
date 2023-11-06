#include <torch/torch.h>
#include <iostream>

struct Net : torch::nn::Module {
    Net(int64_t N, int64_t M) {
        W = register_parameter("W", torch::randn({ N, M }));
        b = register_parameter("b", torch::randn(M));
    }
    torch::Tensor forward(torch::Tensor input) {
        return torch::addmm(b, input, W);
    }
    torch::Tensor W, b;

    torch::nn::Linear linear = nullptr;
    torch::Tensor another_bias;
};

auto main(void) -> int {
    torch::Tensor tensor = torch::eye(3);
    std::cout << tensor << "\n";

    return EXIT_SUCCESS;
}
