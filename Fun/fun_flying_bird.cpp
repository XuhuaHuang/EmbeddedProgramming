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

	cout << "\n\nWarning! China just launched all the nuclear weapon they have!" << endl;
	cout << "Estimatting reamaining time to arrive North America...\n" << endl;
	for (int countDown = 10; countDown > 0; countDown--)
	{
		cout << countDown;
		cout << "\b\b ";
		Sleep(1000);
	}
	cout << "\n !(Hello, world!)" << endl; // say not hello world
	
	int fixednum = 20;
	int index = 19;

	for (int j = 0; j < fixednum; j++)
	{
		for (int i = 0; i < (fixednum-index); i++)
		{
			cout << ".";
			Sleep(100);
		}
		
		cout << "o";
		Sleep(100);
		cout << "O";
		Sleep(100);
		cout << "o";
		Sleep(100);

		for(int k = 0; k < index; k++)
		{
			cout << ".";
			Sleep(100);
		}
		cout << endl;
		//printf("\r");
		index--;
	}
	
	int threeDigit;
	cout << "Please enter a three digit number: ";
	cin >> threeDigit;

	cout << "The most significant digit is: " << threeDigit / 100 << endl;
	cout << "The digit at the middle is: " << (threeDigit % 100) / 10 << endl;
	cout << "THe least significant digit is: " << threeDigit % 10 << endl;

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
	
	int a = 4, b = 5, c = 0, d;
	d = /* !a && !b-- || */ !c;
	cout << d;

	return 0;
}
