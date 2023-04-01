/*****************************************************************//**
 * \file   conversion.cpp
 * \brief  Overloaded conversion operator float()
 * 
 * Document highlight: n/a
 * 
 * \author 1879700
 * \date   November 2020
 *********************************************************************/

#include <iostream>

class Fraction
{
private:
    int num;
    int den;

public:
    constexpr Fraction()
        : num(0)
        , den(0)
    {
    };

    constexpr Fraction(int n, int d)
        : num(n)
        , den(d)
    {
    }

    constexpr Fraction(const Fraction& rhs) = default;
    virtual ~Fraction() = default;

    constexpr const int getnum() const { return this->num; }
    constexpr const int getden() const { return this->den; }

    // conversion operator: return float value of fraction 
    constexpr operator float() const
    {
        return float(getnum()) / float(getden());
    }
};

int main(void)
{
    Fraction f(2, 5); // numerator = 2, denominator = 5

    float val = f; // float(val) is overloaded
    std::cout << val;

    return EXIT_SUCCESS;
}
