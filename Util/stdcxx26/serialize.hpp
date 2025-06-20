/**
 * @file serialize.hpp
 * @author Xuhua Huang
 * @brief
 * @version 0.1
 * @date 2025-06-19
 *
 * @copyright Copyright (c) 2025
 *
 */

#pragma once
#ifndef SERIALIZE_HPP
#define SERIALIZE_HPP

#include <print>

namespace util {

    void inspect(const auto& obj) {
        const auto& [...values] = obj;

        std::print("Object has: {} elements\n", sizeof...(values));

        int count = 0;

        (std::print("Elem: {}: {}\n", count++, values), ...);
    }

    void serialize(const auto& obj) {
        const auto& [...values] = obj;
        static_assert(sizeof...(values) == std::size(obj.names));

        std::size_t index = 0;
        std::print("{{");
        (std::print("\"{}\": {}, ", obj.names[index++], values), ...);
        std::print("}}");
    }

}

#endif // !SERIALIZE_HPP
