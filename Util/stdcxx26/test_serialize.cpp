/**
 * @file test_serialize.cpp
 * @author Xuhua Huang
 * @brief
 * @version 0.1
 * @date 2025-06-20
 *
 * @copyright Copyright (c) 2025
 *
 */


#include "serialize.hpp"

#include <print>

struct Data {
    int x;
    int y;
    float z;
    std::string_view str;

    static constexpr std::string_view names[]{
        "x", "y", "z", "str"
    };
};

int main() {
    Data value{ .x = 1, .y = 2, .z = 4.3f, .str = "Hello World" };

    util::inspect(value);
    util::serialize(value);
    return 0;
}
