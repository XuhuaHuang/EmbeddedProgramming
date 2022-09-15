#include <iostream>
#include <cmath>
#include <windows.h>
#include <string>
//#include <stdio.h>

using namespace std;

int main(void)
{
	for (int fly = 0; fly < 10; fly++)
	{
		cout << "v^  ";
		Sleep(500);
		cout << "-^  ";
		Sleep(500); // supposed a flying bird
	}

	return 0;
}
