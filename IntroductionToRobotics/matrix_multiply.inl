template<typename T, size_t M, size_t N, size_t P>
    requires is_matrix_multiplicable_type<T>
inline constexpr // function attributes
    auto
    matrix_multiply(const std::array<std::array<T, N>, M>& A, const std::array<std::array<T, P>, N>& B)
        -> std::array<std::array<T, P>, M>
{
    std::array<std::array<T, P>, M> result{};

    for (size_t i = 0; i < M; ++i)
    {
        for (size_t j = 0; j < P; ++j)
        {
            result[i][j] = 0;
            for (size_t k = 0; k < N; ++k)
            {
                result[i][j] += A[i][k] * B[k][j];
            }
        }
    }

    return result;
}

template<typename T, std::size_t N>
    requires std::is_arithmetic<T>::value
inline std::ostream& operator<<(std::ostream& os, const std::array<T, N>& A)
{
    os << "[";
    for (std::size_t i = 0; i < A.size(); ++i)
    {
        std::cout << A[i];
        if (i < A.size() - 1) [[likely]]
        {
            os << ", ";
        }
        else [[unlikely]]
        {
            continue;
        }
    }
    os << "]";
    return os;
}

template<typename T, std::size_t M, std::size_t N>
    requires std::is_arithmetic<T>::value
inline std::ostream& operator<<(std::ostream& os, const std::array<std::array<T, N>, M>& A)
{
    os << "[";
    for (std::size_t i = 0; i < M; ++i)
    {
        std::cout << A[i];
        if (i < M - 1) [[likely]]
        {
            os << ",\n ";
        }
        else [[unlikely]]
        {
            continue;
        }
    }
    os << "]";
    return os;
}
