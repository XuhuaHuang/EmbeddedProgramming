/**
 * @file zip.hpp
 * @author Xuhua Huang
 * @brief
 * @version 0.1
 * @date 2023-09-19
 *
 * @copyright Copyright (c) 2023
 *
 */

#pragma once
#ifndef ZIP_HPP
#define ZIP_HPP

#include <ranges>
#include <tuple>
#include <vector>

namespace util
{
namespace range
{

template<typename... Ranges>
auto zip(Ranges&&... ranges)
{
    return std::views::zip(std::forward<Ranges>(ranges)...);
}

} // namespace range
} // namespace util

#undef ZIP_HPP // !ZIP_HPP
