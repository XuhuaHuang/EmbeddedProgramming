#include <iostream>
#include <cmath>

using namespace std;

int main(void)
{
	int x = 1, y = 1;
	cout << "Initially, X is: " << x << endl << "Y is: " << y << endl;
	int m, n;
	m = n = 1;
	
	switch (m)
	{
	case 0: // this case is ignored
		x = x * 2;

	case 1: // executed
	{
		switch (n)
		{
		case 1: // executed
			x = x * 2;

		case 2: y = y * 2; // executed
			break;

		case 3:
			x++;
		}
	}
	case 2: // nobreak on previous case, executed
		x++;
		y++;

	case 3: // no break in previous case, executed
		x *= 2;
		y *= 2;
		break;

	default:
		x++;
		y++;

	}
	cout << "\nX is now: " << x << endl << "Y is now: " << y << endl;

	return 0;
}
