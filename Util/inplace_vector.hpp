/**
 * @file inplace_vector.hpp
 * @author Xuhua Huang
 * @brief
 * @version 0.1
 * @date 2023-10-15
 *
 * @copyright Copyright (c) 2023
 *
 */

#include <array>
#include <new>
#include <optional>

template<typename T, std::size_t Size>
class inplace_vector
{
public:
    constexpr T& push_back(const T& t)
    {
        if (size_ == Size)
        {
            throw std::bad_alloc();
        }
        return arr_[size_++].emplace(t);
    }

    constexpr std::size_t size() const { return size_; }

    constexpr T& operator[](std::size_t idx) { return *arr_[idx]; }

private:
    std::array<std::optional<T>, Size> arr_;
    std::size_t                        size_ = 0;
};

/// @brief Unit tests using Immediately-Invoked Function Expression (IIFE)
static_assert([] {
    inplace_vector<int, 1> v{};
    v.push_back(1);
    return v.size();
}() == 1);

static_assert([] {
    inplace_vector<int, 2> v{};
    v.push_back(1);
    v.push_back(2);
    return v.size();
}() == 2);

static_assert([] {
    inplace_vector<int, 2> v{};
    v.push_back(4);
    v.push_back(2);
    return v[0] + v[1];
}() == 6);

// should not compile
static_assert([] {
    inplace_vector<int, 2> v{};
    v.push_back(1);
    v.push_back(2);
    v.push_back(3);
    return v.size();
}() == 2);
