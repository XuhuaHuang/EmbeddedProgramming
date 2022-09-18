/*****************************************************************//**
 * \file   FunctorLambda.cpp
 * \brief  Demonstration of classes used as functor in C++.
 * 
 * \author Xuhua Huang (xuhua.huang.io@outlook.com)
 * \date   September 2022
 *********************************************************************/

#include <iostream>

namespace functor {

    class add_w_optr {
    public:
        // overloaded operator to be used
        // in the same fashion as calling a function
        constexpr inline int operator()(const int x, const int y) const {
            return x + y;
        }
    };

    class add_w_ctr {
    public:
        explicit add_w_ctr() : a(0), b(0), result(0) {}
        add_w_ctr(const int a, const int b) : a(a), b(b), result(a + b) {}

        constexpr inline int get_result(void) const {
            return result;
        }

        add_w_ctr(const add_w_ctr&) = delete;
        add_w_ctr(add_w_ctr&&) = delete;

    private:
        int a;
        int b;
        int result;
    };
}

int main(void)
{
    int a = 3, b = 4;

    const functor::add_w_optr add;
    // add is an instantiation of class functor::add_w_optr
    // the following 2 lines are equivalent:
    // int result = add.operator()(a, b);
    int result = add(a, b);
    std::cout << "Result with operator: " << result << "\n";

    const functor::add_w_ctr add_df;
    std::cout << "Result with default constructor: " << add_df.get_result() << "\n";

    const functor::add_w_ctr add_ol(a, b);
    std::cout << "Result with overloaded constructor: " << add_ol.get_result() << "\n";

    std::cin.get();
    return 0;
}
