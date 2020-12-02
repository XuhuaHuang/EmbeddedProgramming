/*****************************************************************//**
 * \file   mock_main.cpp
 * \brief  contains example test cases for base class 'Game'
 * 
 * \author Xuhua
 * \date   December 2020
 *********************************************************************/

#include <iostream>
#include <string>
#include "mock.h"

using namespace std;

int main(void)
{
	// Teasting base class 'Game'
	cout << "Testing base class Game" << endl
		 << "With default constructor" << endl;
	Game myGame; // create a Game object
	cout << "Name = " << myGame.getName() << endl;

	// testing overloaded constructor with initial name
	Game myGame2("Hide and Seek");
	cout << "Name for mygame2 = " << myGame2.getName() << endl;
	
	// testing Game class printInfo function
	myGame2.printInfo();

	return 0;
}
