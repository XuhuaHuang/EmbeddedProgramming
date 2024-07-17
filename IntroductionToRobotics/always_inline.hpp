/**
 * @file always_inline.hpp
 * @author Xuhua Huang
 * @brief
 * @version 0.1
 * @date 2024-05-31
 *
 * @copyright Copyright (c) 2024
 *
 */

#pragma once
#ifndef ALWAYS_INLINE_HPP
#define ALWAYS_INLINE_HPP

#if defined(_MSC_VER)
// Microsoft Visual C++
#define INLINE inline __forceinline
#elif defined(__GNUC__) || defined(__clang__)
// GCC or Clang
#define INLINE __attribute__((always_inline)) inline
#else
// Default fallback
#define INLINE inline
#endif

#endif // !ALWAYS_INLINE_HPP
