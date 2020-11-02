#include <iostream>
#include <cmath>
//#include <windows.h>
//#include <string>
//#include <stdio.h>

using namespace std;

int main(void)
{
	int threeDigit;
	cout << "Please enter a three digit number: ";
	cin >> threeDigit;

	cout << "The most significant digit is: " << threeDigit / 100 << endl;
	cout << "The digit at the middle is: " << (threeDigit % 100) / 10 << endl;
	cout << "THe least significant digit is: " << threeDigit % 10 << endl;

	return 0;
}
