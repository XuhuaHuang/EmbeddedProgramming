/*****************************************************************//**
 * \file   CIRCUIT_main.cpp
 * \brief  Contains various test cases for class and functions
 * 
 * \author Xuhua Huang
 * \date   December 2020
 *********************************************************************/

#include "final.h"

using namespace std;

int main(void)
{
	// Testing class 'COMPONENT'
	// creating an object named 'component1'
	COMPONENT component1; // testing default constructor
	cout << "\nTestinng class \'COMPONENT\'" << endl
		 << "An object of class \'COMPONENT\' named \'component1\' has been created" << endl
		 << "Default constructor and setValue function have been tested" << endl
		 << "Calling \'printInfo\' function. Expecting value = 0.00" << endl;
	component1.printInfo(); // expecting 0.00
	
	COMPONENT component2(12.5); // testing overloaded constructor
	cout << "\nAnother object of class \'COMPONENT\' named \'component2\' has been created" << endl
		 << "Overloaded constructor and setValue function have been tested with argument." << endl
		 << "Calling \'printInfo\' function. Expecting value = 12.50" << endl;
	component2.printInfo(); // expecting 12.50
	// end of class 'COMPONENT' test
	
	// Testing class 'RESISTOR'
	// creating an object named 'resistor1'
	RESISTOR resistor1; // testing default constructor
	cout << "\nTestinng class \'RESISTOR\'" << endl
		 << "An object of class \'RESISTOR\' named \'resistor1\' has been created" << endl
		 << "Default constructor and setValue function have been tested" << endl
		 << "Calling \'printInfo\' function. Expecting value = 0.00, powerRating = 0.00" << endl;
	resistor1.printInfo(); // expecting two 0.00s

	RESISTOR resistor2(330, 0.5);
	cout << "\nAnother object of class \'RESISTOR\' named \'resistor2\' has been created" << endl
		 << "Overloaded constructor and setValue function have been tested with argument." << endl
		 << "Calling \'printInfo\' function. Expecting value = 330.00 and powerRating = 0.5" << endl;
	resistor2.printInfo(); // expecting 330.00 and 0.50
	// end of class 'RESISTOR' test

	// Testing class 'INDUCTOR'
	// crating a pointer to an INDUCTOR object
	INDUCTOR* ptrIND = new INDUCTOR;
	cout << "\nTestinng class \'INDUCTOR\'" << endl
		 << "A pointer of class \'INDUCTOR\' named \'ptrIND\' has been created" << endl
		 << "Expecting base and derived class constructor called" << endl
		 << "Calling \'printInfo\' function. Expecting value = 0.00047 and reactance = 0.00" << endl;
	
	ptrIND->printInfo(); // expecting value = 0.00047 and reactance = 0.00
	ptrIND->calcReactance(5000); // pass 5000 Hz as frequency
	cout << "\nReactance for pointer \'ptrIND\' has been updated" << endl
		 << "Calling \'printInfo\'  function" << endl
		 << "Expecting inductance = 0.00047 and reactance = 14.758" << endl;
	ptrIND->printInfo();


	cout << "\nTesting default argument for function \'calcReactance\' for class INDUCTOR" << endl
		 << "Calling \'printInfo\'  function" << endl
		 << "Expecting inductance = 0.00047 and reactance = 2.9516" << endl;
	ptrIND->calcReactance(); // frequency defaulted to 1000 Hz
	ptrIND->printInfo();
	//end of class 'INDUCTOR' test
	
	// Tesing class 'CIRCUIT'
	CIRCUIT circuit1;
	cout << "\nTestinng class \'CIRCUIT\'" << endl
		 << "An object named \'circuit1\' has ben created" << endl
		 << "Calling \'printInfo\' function" << endl
		 << "Expecting resistor = 0.00, powerRating = 0.0" << endl
		 << "inductance = 0.00047, reactance = 0.00" << endl;
	circuit1.printInfo();

	cout << "\nUpdating informatiuon for \'circuit1\'" << endl;
	circuit1.setFrequency(20000); // update the circuit frequency
	RESISTOR resistor3(220, 0.25); // creating a resistor object
	circuit1.setResistor(resistor3); // setting the resistor for the circuit
	(circuit1.getInductor())->calcReactance(circuit1.getFrequency()); 
	// updating reactance with current circuit frequency
	
	cout << "\nFinished updating information \'circuit1\'" << endl
		 << "Calling \'printInfo\' function" << endl
		 << "Expecting:" << endl
		 << "\tFrequency = 20000" << endl
		 << "\tResistance = 220, powerRating = 0.00" << endl
		 << "\tInductance = 0.00047, reactance = 59.032" << endl;
	circuit1.printInfo();

	delete ptrIND;
	return 0;
}
