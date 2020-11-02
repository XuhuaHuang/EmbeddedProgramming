#include <windows.h>
#include <iostream>
#include <string>

using namespace std;

int main(void)
{
	string greeting = "Hello, world!";

	for (int iter = 0; iter < greeting.length(); iter++)
	{
		cout << greeting[iter];
		Sleep(500);
	}
	
	cout << " "; // an extra space to accomdate with the following for loop
	Sleep(1500);

	for (int iter2 = 0; iter2 < greeting.length() ; iter2++)
	{
		cout << "\b\b ";
		//greeting.replace(iter2, 1, " ");
		Sleep(500);
	}

	return 0;
}
