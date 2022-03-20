#include <iostream>
#include <float.h>
#include <string> // grants access to string class
#include <cmath>

using namespace std;

//using std::cout;
//using std::cin;

int main (void)
{
	// boolean value
	bool life_is_good = true;
	cout << boolalpha << life_is_good << endl;
	if (life_is_good) // brackets evaluate the condition and feedback either true or false
		cout << "This is True." << endl;
	
	
	//float and double
	float a = 0;
	double b;
	long double c;
	
	cout << fixed << a << endl;
	// std::fixed gets rid of scientific notation
	
	cout << LDBL_DIG << endl; 
	// this line is evaluating up to how many digits we can trust on these variables
	// 6 for float, 15 for double, 18 for long double
	
	// string
	string greeting = "What's up?";
	cout << greeting.find_first_of("aeiou") << endl; // string member modifier or methods
	/*	if not found, npos == -1
		however, it's an unsigned integer 
		negative value makes it go 1 lower to a tremendously big
	*/
	if (greeting.find_first_of("!") == -1) 
		cout << "NOT FOUND!" << endl;
	
	if (greeting.compare("What's up?") == 0)
		cout << "EQUALS!" << endl;
	// compare function returns a bool 0 to indicate found

	// hex and octal int
	int x = 0x30; // 0x indicates this is a hex int
	// second digit is 16^1 = 16, 16 * 3 = 48

	int x = 030; // 0 indicates an octal int
	// second digit is 8^1 = 8, 8 * 3 = 24
	
	return 0;
}
