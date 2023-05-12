// clang-format off
/*****************************************************************//**
 * \file   fun_fibonacci_series_std11.cpp
 * \brief  work with C++11 to generate a Fibonacci series
 * 
 * \author Xuhua
 * \date   November 2020
 *********************************************************************/
// clang-format on

#include <iostream>
#include <string>
#include <vector>

class Fibonacci
{
private:
    int               size;
    std::vector<long> data;

public:
    constexpr Fibonacci() noexcept = default;
    // constructor that inherits the item constructor
    constexpr Fibonacci(int size) noexcept(true)
        : size(size)
    {
    }

    // other member functions
    void create_series(void);
    void print_series(void);
};

int main(int argc, char* argv[])
{
    if (argc == 2)
    {
        int              value = std::stoul(argv[1], nullptr, 10);
        static Fibonacci fibo(value);
        fibo.create_series();
        fibo.print_series();
    }

    return 0;
}

// creates a Fibonacci series
void Fibonacci::create_series(void)
{
    data.push_back(0);
    data.push_back(1);
    for (int i = 2; i < size; ++i)
    {
        data.push_back(data[i - 2] + data[i - 1]);
    }
}

// method is used to print the series
void Fibonacci::print_series(void)
{
    for (long i : data) // range based for loops
    {
        std::cout << i << ", ";
    }
}
