/**
 * @file matrix_transpose.inl
 * @author Xuhua Huang
 * @brief
 * @version 0.1
 * @date 2023-09-01
 *
 * @copyright Copyright (c) 2023
 *
 */

template<typename T, std::size_t M, std::size_t N>
    requires std::is_arithmetic_v<T> && std::is_copy_assignable_v<T>
[[nodiscard]]
inline __attribute__((always_inline)) constexpr // function attributes
    auto matrix_transpose(const std::array<std::array<T, N>, M>& A) -> std::array<std::array<T, M>, N>
{
    using return_type = std::array<std::array<T, M>, N>;

    if (M == 0U or N == 0U)
    {
        return {};
    }

    return_type result{};

    for (std::size_t i = 0U; i < M; i++)
    {
        for (std::size_t j = 0U; j < N; j++)
        {
            result[j][i] = A[i][j];
        }
    }

    return result;
}
