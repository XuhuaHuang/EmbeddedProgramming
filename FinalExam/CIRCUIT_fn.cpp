/*****************************************************************//**
 * \file   CIRCUIT_fn.cpp
 * \brief  Contains all function definitions 
 *		   excluding one-line functions
 * 
 * \author Xuhua Huang
 * \date   December 2020
 *********************************************************************/

#include "CIRCUIT.h"

using namespace std;

#ifndef PI
#define PI 3.14159265359
#endif

/*************************************
	 COMPONENT CLASS CONSTRUCTORS
**************************************/
COMPONENT::COMPONENT() // default constructor
{
	cout << "\n[DECONST]COMPONENT" << endl;
	setValue(0.00);
}

COMPONENT::COMPONENT(double initValue) // overloaded constructor
{
	cout << "\n[OLCONST]COMPONENT" << endl;
	setValue(initValue);
}

void COMPONENT::printInfo(void)
{
	cout << "\n[fn][COMPONENT]Private member \'value\' = " << getValue();
	return;
}

/***************************************
	 RESISTOR CLASS MEMBER FUNCTIONS
****************************************/
RESISTOR::RESISTOR() // default constructor
{
	// expecting base class COMPONENT default constructor called
	cout << "\n[DFCONST]RESISTOR" << endl
		 << "[DFCONST][RESISTOR]Expecting base class COMPONENT default constructor called" << endl;
	setPowerRating(0.00);
}

RESISTOR::RESISTOR(double initValue, double initPowerRating) : COMPONENT(initValue)
{
	// expecting base class COMPONENT overloaded constructor called
	cout << "\n[OLCONST]RESISTOR" << endl
		 << "[OLCONST][RESISTOR]Expecting base class COMPONENT overloaded constructor called" << endl
		 << "[OLCONST][RESISTOR]Invoking mutator for private member \'powerRating\'." << endl;
	setPowerRating(initPowerRating);
}

void RESISTOR::printInfo(void)
{
	cout << "\n[fn][RESISTOR]Invoking base class \'COMPONENT\' printInfo function." << endl;
	COMPONENT::printInfo();
	// appending unit 'Ohms' at the end
	cout << " Ohms" << endl;
	
	cout << "[fn][RESISTOR]Private member \'powerRating\' = " << fixed 
		 << getPowerRating() << " W" << endl;
}

/***************************************
	 INDUCTOR CLASS MEMBER FUNCTIONS
****************************************/
INDUCTOR::INDUCTOR() : COMPONENT(0.00047) // default constructor pass 0.00047 henry
{
	cout << "\n[DECONST]INDUCTOR" << endl
		 << "[DFCONST][INDUCTOR]Expecting base class COMPONENT default constructor called" << endl
		 << "[DFCONST][INDUCTOR]Called base class overloaded constructor" << endl;
	setReactance(0.00);
}

INDUCTOR::~INDUCTOR() // destructor
{
	cout << "\n[DESTRUCT][INDUCTOR]Destructing object of class \'INDUCTOR\' >_<" << endl;
}

void INDUCTOR::calcReactance(double frequency) // default argument removed
{
	cout << "\n[fn][INDUCTOR]calcReactance" << endl;
	setReactance( 2*PI*frequency*getValue() );
}

void INDUCTOR::printInfo(void)
{
	cout << "\n[fn][INDUCTOR]Invoking base class \'COMPONENT\' printInfo function." << endl;
	COMPONENT::printInfo();
	// appending unit 'H' at the end
	cout << " H" << endl
		 << "[fn][INDUCTOR]Private member \'reactance\' = " << getReactance() << " Ohms" << endl;
}

/***************************************
	 CIRCUIT CLASS MEMBER FUNCTIONS
****************************************/
CIRCUIT::CIRCUIT()
{
	cout << "\n[DFCONST]CIRCUIT" << endl
		 << "[DFCONST][CIRCUIT]A pointer to an INDUCTOR object is created" << endl
		 << "[DFCONST][CIRCUIT]Expecting class INDUCTOR default constructor called" << endl;
	setFrequency(10000);
	setInductor(new INDUCTOR);
}

CIRCUIT::~CIRCUIT()
{
	cout << "\n[DESTRUCT]CIRCUIT" << endl
		 << "[DESTRUCT][CIRCUIT]Dedicated pointer to an INDUCTOR object is deleted" << endl
		 << "[DESTRUCT][CIRCUIT]Expecting class INDUCTOR destructor called" << endl;
	delete inductor;
}

void CIRCUIT::printInfo(void)
{
	cout << "\n[fn][CIRCUIT]printInfo" << endl
		 << "[fn][CIRCUIT]Circuit frequency = " << getFrequency() << " Hz" << endl
		 << "[fn][CIRCUIT]Invoking printInfo for class RESISTOR and INDUCTOR" << endl;
	(getResistor()).printInfo();
	(getInductor())->printInfo(); // getInductor() returns a pointer
}
