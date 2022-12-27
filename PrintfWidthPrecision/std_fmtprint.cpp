/*****************************************************************//**
 * \file   std_fmtprint.cpp
 * \brief  
 * 
 * \author Xuhua Huang
 * \date   December 20, 2022
 *********************************************************************/

#include <array>
#include <cctype>
#include <format>
#include <ranges>
#include <numbers>
#include <iostream>
#include <cstdlib>
#include <array>
#include <filesystem>
#include <print>

auto demo_stdprint_tofile() -> void {
    std::print("{0} {2}{1}!\n", "Hello", 23, "C++"); // overload (1)

    const auto tmp{ std::filesystem::temp_directory_path() / "test.txt" };

    if (std::FILE * stream{ std::fopen(tmp.c_str(), "w") })
    {
        std::print(stream, "File: {}", tmp.string()); // overload (2)
        std::fclose(stream);
    }

    return;
}

int main()
{
    std::array<char, 24> buf;
    std::format_to(buf.begin(), "{:.15f}", std::numbers::sqrt2);

    unsigned num{}, sum{};

    auto v = buf
        | std::views::filter(isdigit)
        | std::views::transform([](char x) { return x - '0'; })
        | std::views::take_while([&sum](char) { return sum < 42; })
        ;

    for (auto n : v) {
        sum += n;
        ++num;
    }

#ifdef __cpp_lib_print
    std::print(
        std::cout,
        "√2 = {}...\n"
        "The sum of its first {} digits is {}{}\n",
        std::numbers::sqrt2, num, sum, '.'
    );
#else
    std::cout <<
        std::format(
            "√2 = {}...\n"
            "The sum of its first {} digits is {}{}\n",
            std::numbers::sqrt2, num, sum, '.'
        );
#endif

    return EXIT_SUCCESS;
}
