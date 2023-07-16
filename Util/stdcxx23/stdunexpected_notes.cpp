/**
 * @file stdunexpected_notes.cpp
 * @author Xuhua Huang
 * @brief Notes on working with std::unexpected in C++23.
 *
 * cl .\stdunexpected_notes.cpp /std:c++latest /EHsc
 * .\stdunexpected_notes
 *
 * g++ stdunexpected_notes.cpp -std=c++2b -o stdunexpected_notes -Wall -Wextra -O3 -Wno-pragma-once-outside-header
 *
 * @version 0.1
 * @date 2023-07-15
 *
 * @copyright Copyright (c) 2023
 *
 */

#include <expected>
#include <iostream>

enum class error
{
    compile_time_error,
    runtime_error
};

[[nodiscard]] auto unexpected_runtime_error() -> std::expected<int, error>
{
    return std::unexpected(error::runtime_error);
}

int main()
{
    const auto e = unexpected_runtime_error();

    e.and_then([](const auto& e) -> std::expected<int, error> {
         std::cout << "and_then: " << int(e); // not printed
         return {};
     }).or_else([](const auto& e) -> std::expected<int, error> {
        std::cout << "or_else: " << int(e); // prints this line
        return {};
    });

    return 0;
}
