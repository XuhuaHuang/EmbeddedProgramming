/*****************************************************************//**
 * \file   MemberFnAmpersand.cpp
 * \brief  
 * 
 * \author Xuhua Huang
 * \date   November 2022
 *********************************************************************/

#include <iostream>

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

int main(void)
{
    Arg g1{5};                                   /* instanciation with innitializer_list */
    std::cout << g1.getArg() << "\n";            /* expecting int& getArg() & */
    std::cout << std::move(g1).getArg() << "\n"; /* expecting int getArg() && */
    return 0;
}
