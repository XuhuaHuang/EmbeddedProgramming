// clang-format off
/*****************************************************************//**
 * \file   functor_lambda.cpp
 * \brief  Demonstration of classes used as functor in C++.
 * 
 * \author Xuhua Huang
 * \date   September 2022
 *********************************************************************/

#include <iostream>

namespace functor {
    class add_w_optr {
    public:
        explicit add_w_optr() = default;
        add_w_optr(const add_w_optr&) = delete;
        add_w_optr(add_w_optr&&) = delete;
        // overloaded operator to be used
        // in the same fashion as calling a function
        constexpr inline int operator()(const int x, const int y) const {
            return x + y;
        }
    };

    class add_w_ctr {
    public:
        explicit add_w_ctr() : a(0), b(0), result(0) {}
        explicit add_w_ctr(const int a, const int b) : a(a), b(b), result(a + b) {}

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

namespace calc {
    class tax {
    public:
        explicit tax(const float rate, int base): rate(rate), base(base) {}
        explicit tax() : rate((float)0.15), base(11'000) {}

        constexpr inline double operator()(void) const {
            return base * rate;
        }

        constexpr inline double operator()(const float salary) const {
            return (salary - base) * rate;
        }

        tax(const tax&) = delete;
        tax(tax&&) = delete;

    private:
        float rate;
        int base;
    };
}

// clang-format on
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

    const calc::tax tax_default{};
    std::cout << "Default tax payer: " << tax_default() << "\n";

    // pay 15% tax when income is above 11k, lower than 24k
    // pay 25% tax of the part above 24k, lower than 60k
    const calc::tax tax_mid_income{0.25, 24'000};
    std::cout << "Low income tax payer: " << tax_mid_income(45'000) + tax_default() << "\n";

    // pay 40% tax of the part above 60k, lower than 90k
    const calc::tax tax_high_income{0.35, 60'000};
    std::cout << "High income tax payer: " << tax_high_income(90'000) + tax_mid_income(60'000) << "\n";

    system("pause");
    return 0;
}
