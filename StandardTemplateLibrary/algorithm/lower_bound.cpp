/**
 * @file lower_bound.cpp
 * @author Xuhua Huang
 * @brief
 * @version 0.1
 * @date 2023-12-04
 *
 * @copyright Copyright (c) 2023
 *
 */

#include <algorithm>
#include <array>
#include <iostream>
#include <vector>

#include "Helper/generic_container.hpp"

struct PriceInfo
{
    constexpr inline explicit((false)) PriceInfo(const double p)
        : price{p}
    {
    }
    double price;
};

int main()
{
    constexpr std::array<int, 6U> data{
        {1, 2, 4, 5, 5, 6}
    };
    using helper::generic_container::operator<<;
    std::cout << data << "\n";

    for (int i = 0; i < 8; ++i)
    {
        // search for first element x such that i ≤ x
        auto lower = std::lower_bound(data.begin(), data.end(), i);

        std::cout << i << " <= ";
        lower != data.end() ? std::cout << *lower << " at index " << std::distance(data.begin(), lower)
                            : std::cout << "not found";

        std::cout << "\n";
    }

    constexpr std::array<PriceInfo, 5U> prices{
        {{100.0}, {101.5}, {102.5}, {102.5}, {107.3}}
    };

    for (const double to_find : {102.5, 110.2})
    {
        auto prc_info = std::lower_bound(prices.begin(), prices.end(), to_find,
                                         [](const PriceInfo& info, double value) { return info.price < value; });

        prc_info != prices.end() ? std::cout << prc_info->price << " at index " << prc_info - prices.begin()
                                 : std::cout << to_find << " not found";

        std::cout << "\n";
    }

    return EXIT_SUCCESS;
}
