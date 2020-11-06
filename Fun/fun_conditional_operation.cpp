#include <iostream>
#include <cmath>

using namespace std;

int main(void)
{
	cout << "\nConditional Operation" << endl;
	int x = 1, y = 3;
	int result = (y - x) > 0 ? y - x : x - y;
	cout << result << endl;
	
	/*
	if (y - x > 0)
		result = y - x;
	else
		result = x - y;
	*/
  
	return 0;
}
