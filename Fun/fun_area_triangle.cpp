#include <iostream>
#include <cmath>

using namespace std;

int main(void)
{
	double a = 0, b = 0, c = 0;
	cout << "Please enter the length of the first side of the triangle: ";
	cin >> a;

	cout << "Please enter the length of the second side of the triangle: ";
	cin >> b;

	cout << "Please enter the third length of the side of the triangle: ";
	cin >> c;

	double s = (1 / 2) * (a + b + c);
	double area = sqrt(s * (s - a) * (s - b) * (s - c));

	cout << "\nThe area of the triangle you just entered is: " << area << endl;

	return 0;
}
