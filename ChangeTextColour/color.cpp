// -*- coding:utf-8; mode:c++; mode:auto-fill; fill-column:80; -*-

/// @file      example-color.cpp
/// @brief     Example program using ANSI color ostream manipulators.
/// @author    J. Arrieta <Juan.Arrieta@nablazerolabs.com>
/// @date      March 14, 2017
/// @copyright (c) 2017 Nabla Zero Labs
///
/// This code is released under The MIT License
///
/// Copyright 2017 Nabla Zero Labs
///
/// Permission is hereby granted, free of charge, to any person obtaining a copy
/// of this software and associated documentation files (the "Software"), to
/// deal in the Software without restriction, including without limitation the
/// rights to use, copy, modify, merge, publish, distribute, sublicense, and/or
/// sell copies of the Software, and to permit persons to whom the Software is
/// furnished to do so, subject to the following conditions:
///
/// The above copyright notice and this permission notice shall be included in
/// all copies or substantial portions of the Software.
///
/// THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
/// IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
/// FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
/// AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
/// LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING
/// FROM, OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS
/// IN THE SOFTWARE.

// C++ Standard Library
#include <iostream>

// Color Library
#include "color.hpp"

int main(void)
{
  std::cout << color::red          << "this is red\n"
            << color::green        << "this is green\n"
            << color::yellow       << "this is yellow\n"
            << color::blue         << "this is blue\n"
            << color::magenta      << "this is magenta\n"
            << color::cyan         << "this is cyan\n"
            << color::bold_red     << "this is bold_red\n"
            << color::bold_green   << "this is bold_green\n"
            << color::bold_yellow  << "this is bold_yellow\n"
            << color::bold_blue    << "this is bold_blue\n"
            << color::bold_magenta << "this is bold_magenta\n"
            << color::bold_cyan    << "this is bold_cyan\n"
            << color::reset
            << color::bg_red       << "this is bg_red"     << color::reset << "\n"
            << color::bg_green     << "this is bg_green"   << color::reset << "\n"
            << color::bg_yellow    << "this is bg_yellow"  << color::reset << "\n"
            << color::bg_blue      << "this is bg_blue"    << color::reset << "\n"
            << color::bg_magenta   << "this is bg_magenta" << color::reset << "\n"
            << color::bg_cyan      << "this is bg_cyan"    << color::reset << "\n"
            << color::reset;
            
            return 0;
}
