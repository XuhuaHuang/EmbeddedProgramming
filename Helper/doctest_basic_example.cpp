// cl .\doctest_basic_example.cpp /W4 /Zc:__cplusplus /EHsc /std:c++latest /experimental:module
// .\doctest_basic_example.exe
// https://github.com/doctest/doctest/blob/master/doc/markdown/tutorial.md
// https://github.com/doctest/doctest/blob/master/doc/markdown/main.md

#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN
#include "doctest.hpp"

#include <iostream>
#include <vector>

consteval int factorial(int number)
{
    static_assert(std::is_constant_evaluated());
    return number <= 1 ? number : factorial(number - 1) * number;
}

TEST_CASE("testing the factorial function")
{
    CHECK(factorial(1) == 1);
    CHECK(factorial(2) == 2);
    CHECK(factorial(3) == 6);
    CHECK(factorial(10) == 3628800);
}

consteval int fibonacci(int n)
{
    if (n == 0 || n == 1)
        return n;
    return fibonacci(n - 1) + fibonacci(n - 2);
}

TEST_CASE("testing the fibonacci function")
{
    CHECK(fibonacci(0) == 0);
    CHECK(fibonacci(1) == 1);
    CHECK(fibonacci(2) == 1);
    CHECK(fibonacci(3) == 2);
    CHECK(fibonacci(10) == 55);
}

TEST_CASE("vectors can be sized and resized")
{
    std::vector<int> v(5);

    REQUIRE(v.size() == 5);
    REQUIRE(v.capacity() >= 5);

    SUBCASE("adding to the vector increases its size")
    {
        v.push_back(1);

        CHECK(v.size() == 6);
        CHECK(v.capacity() >= 6);
    }
    SUBCASE("reserving increases just the capacity")
    {
        v.reserve(6);

        CHECK(v.size() == 5);
        CHECK(v.capacity() >= 6);
    }
}
