#include <iostream>
#include <math.h>

using namespace std;

int main(void)
{
	int numPrecision = 2;

	cout.precision(numPrecision);

	double a = 0;
	int b = 1;

	cout << "Value for \"double a\" is: " << fixed << a << endl;
	cout << "Value for \"int b\" is: " /* << fixed */ << b << endl;

	return 0;
}
