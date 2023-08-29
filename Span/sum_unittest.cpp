// g++ sum_unittest.cpp -std=c++2b -o sum_unittest -Wall -Wextra -O3 -Wno-pragma-once-outside-header
// .\sum_unittest

#include <array>
#include <numeric>
#include <span>

#include "sum.hpp"

constexpr std::array a{1, 2, 3, 4, 5};
constexpr std::span  s{a};

int main(void)
{
    static_assert(15 == util::span::sum(s));
    return 0;
}
