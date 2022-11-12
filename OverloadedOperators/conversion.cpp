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
    int num, den;

public:
    Fraction(int n, int d) { num = n; den = d; }

    // conversion operator: return float value of fraction 
    operator float() const
    {
        return float(num) / float(den);
    }
};

int main(void)
{
    Fraction f(2, 5); // numerator = 2, denominator = 5

    float val = f; // float(val) is overloaded
    std::cout << val;

    return EXIT_SUCCESS;
}
