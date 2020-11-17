/*****************************************************************//**
 * \file   plus_struct.cpp
 * \brief  Overloaded operator in a structure
 * 
 * Document highlight: inheriting from item constructor	
 *
 * \author Xuhua
 * \date   November 2020
 *********************************************************************/

#include <iostream>
using namespace std;

struct Complex
{
public:
	Complex(double r, double i) : re(r), im(i) {} // inheriting from item constructor
	// equivalent to: Complex(double r = 0, double i = 0) { re = r; im = i; }
	
	Complex operator+(Complex& other);
	void Display() { cout << re << ", " << im << endl; }

private:
	double re, im;
};

// Operator overloaded using a member function
Complex Complex::operator+(Complex& other)
{
	return Complex(re + other.re, im + other.im);
}

int main() {
	Complex a = Complex(1.2, 3.4);
	Complex b = Complex(5.6, 7.8);
	Complex c = Complex(0.0, 0.0);

	c = a + b;
	c.Display();
}
