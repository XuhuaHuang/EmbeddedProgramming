/*****************************************************************//**
 * \file   plus_friend.cpp
 * \brief  Global overloaded operator plus made friend of the class
 * 
 * Doecument highlight: default argument used in line 19
 * 
 * \author 1879700
 * \date   November 2020
 *********************************************************************/

#include<iostream> 
using namespace std;

class Complex {
private:
    int real, imag;

public:
    Complex(int r = 0, int i = 0) { real = r;   imag = i; }
    // using default argument

    void print() { cout << real << " + i" << imag << endl; }

    // The global operator function is made friend of this class so 
    // that it can access private members 
    friend Complex operator + (Complex const&, Complex const&);
};


Complex operator+ (Complex const& c1, Complex const& c2)
{
    return Complex(c1.real + c2.real, c1.imag + c2.imag);
}


int main(void)
{
    Complex c1(10, 5), c2(2, 4);
    Complex c3 = c1 + c2; // An example call to "operator+" 
    c3.print();
    
    return 0;
}
