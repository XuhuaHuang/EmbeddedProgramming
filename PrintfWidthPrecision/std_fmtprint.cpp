// clang-format off
/*****************************************************************//**
 * \file   std_fmtprint.cpp
 * \brief  
 * 
 * \author Xuhua Huang
 * \date   December 20, 2022
 *********************************************************************/
// clang-format on

#include <array>
#include <cctype>
#include <cstdlib>
#include <filesystem>
#include <format>
#include <iostream>
#include <numbers>
#include <print>
#include <ranges>

auto stdprint_tofile() -> void
{
    std::print("{0} {2}{1}!\n", "Hello", 23, "C++"); // overload (1)

    const std::filesystem::path tmp{std::filesystem::temp_directory_path() / "test.txt"};

    if (std::FILE * stream{std::fopen(reinterpret_cast<const char*>(tmp.c_str()), "w")})
    {
        std::print(stream, "File: {}", tmp.string()); // overload (2)
        std::fclose(stream);
    }

    return;
}

int main(int argc, char const* argv[])
{
    std::println("{} arguments passed to main! Hello, world!", argc);
    std::println("{}", argv[0]);

    std::array<char, 24> buf;
    std::format_to(buf.begin(), "{:.15f}", std::numbers::sqrt2);

    unsigned num{}, sum{};

    // clang-format off
    auto v = buf
        | std::views::filter(isdigit)
        | std::views::transform([](char x) { return x - '0'; })
        | std::views::take_while([&sum](char) { return sum < 42; });
    // clang-format on

    for (auto n : v)
    {
        sum += n;
        ++num;
    }

#ifdef __cpp_lib_print
    std::print(std::cout,
               "√2 = {}...\n"
               "The sum of its first {} digits is {}{}\n",
               std::numbers::sqrt2, num, sum, '.');
#else
    std::cout << std::format("√2 = {}...\n"
                             "The sum of its first {} digits is {}{}\n",
                             std::numbers::sqrt2, num, sum, '.');
#endif

    return EXIT_SUCCESS;
}
