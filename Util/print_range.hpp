// clang-format off
/*****************************************************************//**
 * \file   print_range.hpp
 * \brief  Template function to print std::ranges of any types.
 * 
 * \author Xuhua Huang
 * \date   November 28, 2022
 *********************************************************************/
// clang-format on

#ifndef PRINT_RANGE_HPP
#define PRINT_RANGE_HPP

#ifndef _IOSTREAM_
#include <iostream>
#endif

#ifndef _RANGES_
#include <ranges>
#endif

namespace util
{
namespace range
{

void print_range(std::ranges::viewable_range auto&& range, bool need_delim = false, size_t depth = 0)
{
    std::cout << "[";

    bool first_token = false;

    for (auto& v : range)
    {
        if (first_token && need_delim)
        {
            std::cout << ", ";
        }

        // continue to recursively call current function
        // if it is still a range
        // or else print it as a normal element
        if constexpr (requires { print_range(v); })
        {
            if (first_token)
            {
                std::cout << "\n";
                for (auto d = 0; d < depth + 1; ++d)
                {
                    std::cout << " ";
                }
            }
            print_range(v, need_delim, depth + 1);
        }
        // require overloaded operator
        // might be neccessary for a range of customized objects
        else if constexpr (requires operator<<(std::ostream& out, v)->std::ostream&)
        {
            std::cout << v; // single dimension range
        }

        first_token = true;
    }
    std::cout << "]";

    return; // add empty return statement for consistency.
}

} // namespace range
} // namespace util

#endif
