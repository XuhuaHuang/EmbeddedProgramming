/**
 * @file strcat.hpp
 * @author Xuhua Huang
 * @brief
 * @version 0.1
 * @date 2024-03-03
 *
 * @copyright Copyright (c) 2024
 *
 */

#pragma once

#ifndef STRCAT_HPP
#define STRCAT_HPP

#include <string>
#include <spanstream>

namespace util
{

[[nodiscard]]
constexpr auto strcat(auto&&... args)
{
    char             buf[256]{};
    std::ospanstream oss{std::span{buf}};
    ((oss << args), ...);
    const auto span = oss.span();

    return std::string{span.data(), span.size()};
}

} // namespace util

#endif // !STRCAT_HPP
