/*****************************************************************//**
 * \file   plus_class.cpp
 * \brief  
 * 
 * \author Xuhua
 * \date   November 2020
 *********************************************************************/

#include<iostream> 
using namespace std;

class Complex {

private:
    int real, imag;

public:
    Complex(int r = 0, int i = 0) { real = r;   imag = i; }
    // default arguments are both 0s. One-line constructor [default/overloaded]

    // This is automatically called when '+' is used with between two Complex objects 
    Complex operator + (Complex const& obj) {
        Complex res;
        res.real = real + obj.real;
        res.imag = imag + obj.imag;
        return res;
    }

    void print() { cout << real << " + i" << imag << endl; }

};

int main(void)
{
    Complex c1(10, 5), c2(2, 4);
    Complex c3 = c1 + c2; // An example call to "operator+" 
    // the overloaded plus operator belong to the class 'Complex'

    c3.print();

    return 0;
}
