/**
 * @file consteval_filter_unittest.cpp
 * @author Xuhua Huang
 * @brief 
 * @version 0.1
 * @date 2023-06-18
 * 
 * @copyright Copyright (c) 2023
 * 
 */

#include "consteval_filter.hpp"

int main()
{
    using util::range::filter;

    static_assert(std::tuple{1, 2, 3} == filter([] { return std::tuple{1, 2, 3}; }, [](auto) { return true; }));
    static_assert(std::tuple{} == filter([] { return std::tuple{1, 2, 3}; }, [](auto) { return false; }));
    static_assert(std::tuple{1, 3} == filter([] { return std::tuple{1, 2, 3}; }, [](auto v) { return v != 2; }));
    static_assert(std::tuple{2} == filter([] { return std::tuple{1, 2, 3}; }, [](auto v) { return v == 2; }));

    return 0;
}
