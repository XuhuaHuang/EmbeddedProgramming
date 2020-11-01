#include <iostream>
#include <windows.h>
#include <string>

using namespace std;

// function prototype:
string select(string option1, string option2, int userInput, int* comfirm);

int main(void)
{
	int tryAgain = 0;
	string option1 = "bowl", option2 = "washing machine";
	// bowl or washing machine

	do
	{
		//tryAgain = 0;

		int bowlWash = 0;
		cin >> bowlWash;

		string bowlORwashing = select(option1, option2, bowlWash, &tryAgain);
		cout << bowlORwashing << endl;

	} while (tryAgain == 1);

	return 0;
}

string select(string option1, string option2, int userInput, int* comfirm)
{
	//string comfirm = "Invalid, please try again";

	if (userInput == 1)
		return option1;
	else if (userInput == 2)
		return option2;
	else
		*comfirm = 1;
}
