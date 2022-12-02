/*****************************************************************//**
 * \file   main.cpp
 * \brief  Contains various test cases for class and functions
 *
 * To compile and run this circuit program on Windows:
 * $mingw32-make make
 * $./circuit
 *
 * \author Xuhua Huang
 * \date   December 2020
 *********************************************************************/

#include <windows.h>
#include "circuit.hpp"

int main(void)
{
    // Testing class 'COMPONENT'
    // creating an object named 'component1'
    COMPONENT component1; // testing default constructor
    std::cout << "\033[1;32m"; // change colour to green
    std::cout << "\nTesting class \'COMPONENT\'" << "\n"
        << "An object of class \'COMPONENT\' named \'component1\' has been created" << "\n"
        << "Default constructor and setValue function have been tested" << "\n"
        << "Calling \'printInfo\' function. Expecting value = 0.00" << "\n";
    component1.printInfo(); // expecting 0.00

    COMPONENT component2(12.5); // testing overloaded constructor
    std::cout << "\nAnother object of class \'COMPONENT\' named \'component2\' has been created" << "\n"
        << "Overloaded constructor and setValue function have been tested with argument." << "\n"
        << "Calling \'printInfo\' function. Expecting value = 12.50" << "\n";
    component2.printInfo(); // expecting 12.50
    // end of class 'COMPONENT' test

    // Testing class 'RESISTOR'
    // creating an object named 'resistor1'
    RESISTOR resistor1; // testing default constructor
    std::cout << "\033[1;36m"; // change colour to cyan
    std::cout << "\nTesting class \'RESISTOR\'" << "\n"
        << "An object of class \'RESISTOR\' named \'resistor1\' has been created" << "\n"
        << "Default constructor and setValue function have been tested" << "\n"
        << "Calling \'printInfo\' function. Expecting value = 0.00, powerRating = 0.00" << "\n";
    resistor1.printInfo(); // expecting two 0.00s

    RESISTOR resistor2(330, 0.5);
    std::cout << "\nAnother object of class \'RESISTOR\' named \'resistor2\' has been created" << "\n"
        << "Overloaded constructor and setValue function have been tested with argument." << "\n"
        << "Calling \'printInfo\' function. Expecting value = 330.00 and powerRating = 0.5" << "\n";
    resistor2.printInfo(); // expecting 330.00 and 0.50
    // end of class 'RESISTOR' test

    // Testing class 'INDUCTOR'
    // crating a pointer to an INDUCTOR object
    INDUCTOR* ptrIND = new INDUCTOR;
    std::cout << "\033[1;34m"; // change colour to blue
    std::cout << "\nTesting class \'INDUCTOR\'" << "\n"
        << "A pointer of class \'INDUCTOR\' named \'ptrIND\' has been created" << "\n"
        << "Expecting base and derived class constructor called" << "\n"
        << "Calling \'printInfo\' function. Expecting value = 0.00047 and reactance = 0.00" << "\n";

    ptrIND->printInfo(); // expecting value = 0.00047 and reactance = 0.00
    ptrIND->calcReactance(5000); // pass 5000 Hz as frequency
    std::cout << "\nReactance for pointer \'ptrIND\' has been updated" << "\n"
        << "Calling \'printInfo\'  function" << "\n"
        << "Expecting inductance = 0.00047 and reactance = 14.758" << "\n";
    ptrIND->printInfo();


    std::cout << "\nTesting default argument for function \'calcReactance\' for class INDUCTOR" << "\n"
        << "Calling \'printInfo\'  function" << "\n"
        << "Expecting inductance = 0.00047 and reactance = 2.9516" << "\n";
    ptrIND->calcReactance(); // frequency defaulted to 1000 Hz
    ptrIND->printInfo();
    //end of class 'INDUCTOR' test

    // Testing class 'CIRCUIT'
    CIRCUIT circuit1;
    std::cout << "\033[33m"; // change colour to yellow
    std::cout << "\nTesting class \'CIRCUIT\'" << "\n"
        << "An object named \'circuit1\' has been created" << "\n"
        << "Calling \'printInfo\' function" << "\n"
        << "Expecting resistor = 0.00, powerRating = 0.0" << "\n"
        << "inductance = 0.00047, reactance = 0.00" << "\n";
    circuit1.printInfo();

    std::cout << "\nUpdating information for \'circuit1\'" << "\n";
    circuit1.setFrequency(20000); // update the circuit frequency
    RESISTOR resistor3(220, 0.25); // creating a resistor object
    circuit1.setResistor(resistor3); // setting the resistor for the circuit
    (circuit1.getInductor())->calcReactance(circuit1.getFrequency());
    // updating reactance with current circuit frequency

    std::cout << "\nFinished updating information \'circuit1\'" << "\n"
        << "Calling \'printInfo\' function" << "\n"
        << "Expecting:" << "\n"
        << "\tFrequency = 20000" << "\n"
        << "\tResistance = 220, powerRating = 0.00" << "\n"
        << "\tInductance = 0.00047, reactance = 59.032" << "\n";
    circuit1.printInfo();

    delete ptrIND;
    return 0;
}
