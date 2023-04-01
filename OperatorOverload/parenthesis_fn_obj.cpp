// clang-format off
/*****************************************************************//**
 * \file   parenthesis_fn_obj.cpp
 * \brief  overloading the parenthesis operator with function objects
 * 
 * \author Xuhua
 * \date   November 2020
 *********************************************************************/
// clang-format on

#include <iostream>
#include <string>

class Compare
{
public:
    inline constexpr Compare() noexcept                   = default;
    inline constexpr Compare(const Compare& rhs) noexcept = default;
    inline virtual constexpr ~Compare() noexcept          = default;

    // overloading the "()" operator to compare two int
    // return either 'true/1' or 'false/0'
    inline const std::string operator()(int a, int b) const
    {
        std::string result = "false";
        if (a < b)
        {
            result = "true";
        }
        return result;
    }
};

int main(void)
{
    Compare     compare; // create a function object
    int         a   = 5;
    int         b   = 7;
    std::string ans = compare(a, b);
    // using the overloaded () operator
    // of the "Compare" class

    std::cout << ans << "\n";

    // fun with nested for loops
    for (int i = 0; i < 100; i++)
    {
        for (int j = 0; j < 100; j++)
        {
            std::string ans = compare(i, j);
            std::cout << "\nFor " << i << " < " << j << " is " << ans << "\n";
        }
    }

    return 0;
}
