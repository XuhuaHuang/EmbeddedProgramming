#include <iostream>
#include <cmath>

using namespace std;

int main(void)
{
	int value = 0;
	cout << "Reversing a four digit number..." << endl;
	cout << "Please enter a four digits number: ";
	cin >> value;

	/* reading original digits
	* int thousands = (value / 1000 % 10);
	* int hundreds = (value / 100 % 10);
	* int tens = (value / 10 % 10);
	* int ones = (value % 10);
	*/
	
	int reverseValue = (value % 10) * 1000 + (value / 10 % 10) * 100 + (value / 100 % 10) * 10 + (value / 1000 % 10) * 1;
	cout << "The reversed value is now: " << reverseValue << endl;

	return 0;
}
