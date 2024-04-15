// clang-format off
/*****************************************************************//**
 * \file   reference_qualifier.cpp
 * \brief  
 * 
 * cl .\reference_qualifier.cpp /W4 /analyze /Zc:__cplusplus /EHsc /std:c++latest /experimental:module
 * Reference Qualifier
 * 
 * \author Xuhua Huang
 * \date   November 2022
 *********************************************************************/
// clang-format on

#include <iostream>

struct kwarg
{
    kwarg() = delete;
    constexpr inline kwarg(const char* rhs) { kw = rhs; }
    constexpr inline kwarg(const std::string_view& rhs) { kw = rhs; }
    constexpr inline kwarg(std::string_view&& rhs) { kw = std::move(rhs); }

    constexpr inline decltype(auto) operator=(const auto rhs) { return rhs; }

    constexpr inline bool           operator==(const kwarg& rhs)  = delete;
    constexpr inline decltype(auto) operator<=>(const kwarg& rhs) = delete;

private:
    std::string_view kw;
};

struct Arg
{
    int i = 1;

    Arg(int _i)
        : i{_i}
    {
    }

    int getArg() &&
    {
        std::cout << "In member function int getArg() &&"
                  << "\n";
        return i;
    }

    int& getArg() &
    {
        std::cout << "In member function int& getArg() &"
                  << "\n";
        return i;
    }
};

namespace experimental
{
struct Arg
{
    int i = 1;

    inline int getArg(this Arg& arg) { return arg.i; }
    inline int getArg(this const Arg& arg) { return arg.i; }
    inline int getArg(this Arg&& arg) { return arg.i; }
};
} // namespace experimental

int main(void)
{
    Arg g1{5};                                   /* instanciation with innitializer_list */
    std::cout << g1.getArg() << "\n";            /* expecting int& getArg() & */
    std::cout << std::move(g1).getArg() << "\n"; /* expecting int getArg() && */
    return 0;
}
