#ifndef ARGMINMAX_HPP
#define ARGMINMAX_HPP

template<typename T, size_t N>
size_t argmin(const std::array<T, N>& arr)
{
    // Convert the std::array to a torch::Tensor
    torch::Tensor tensor = torch::from_blob(arr.data(), {N}, torch::kFloat32);

    // Get the index of the minimum element
    auto result = tensor.argmin();
    return result.item<int64_t>();
}

template<typename T, size_t N>
size_t argmax(const std::array<T, N>& arr)
{
    // Convert the std::array to a torch::Tensor
    torch::Tensor tensor = torch::from_blob(arr.data(), {N}, torch::kFloat32);

    // Get the index of the maximum element
    auto result = tensor.argmax();
    return result.item<int64_t>();
}

#endif //! ARGMINMAX_HPP
