/*****************************************************************//**
 * \file   circuit.hpp
 * \brief  Contains class declaration for class 
 * COMPONENT, RESISTOR
 * INDUCTOR, and CIRCUIT
 * 
 * \author Xuhua Huang
 * \date   December 2020
 *********************************************************************/

#ifndef CIRCUIT_HPP
#define CIRCUIT_HPP

#ifndef PI
#define PI 3.14159265359
#endif

/*******************************
	COMPONENT CLASS DEFINITION
*******************************/
class COMPONENT
{
public:

	// default and overloaded constructor
	COMPONENT();
	COMPONENT(double initValue);
	
	// set and get functions for private member 'value'
	void setValue(double initValue) { value = initValue; } // mutator
	double getValue() { return value; } // accessors

	// printInfo function
	void printInfo(void);

private:
	double value;
};

/*********************************
	RESISTOR CLASS DEFINITION
*********************************/
// derived class RESISTOR from base class COMPONENT
class RESISTOR : public COMPONENT
{
public:

	// default and overloaded constructor
	RESISTOR();
	RESISTOR(double initValue, double initPowerRating);
	
	// set and get function for newly added private data member powereRating
	void setPowerRating(double initPowerRating) { powerRating = initPowerRating; }
	double getPowerRating() { return powerRating; }
	
	// printInfo function
	void printInfo(void);

private:
	double powerRating;
};

/*********************************
	INDUCTOR CLASS DEFINITION
*********************************/
// derived class INDUCTOR from base class COMPONENT
class INDUCTOR : public COMPONENT
{
public:
	INDUCTOR();
	~INDUCTOR();

	// set and get function for newly added private data member reactance
	void setReactance(double initReactance) { reactance = initReactance; }
	double getReactance() { return reactance; }
	
	// calcReactance and printInfo function
	void calcReactance(double frequency = 1000); // frequency default to 1000
	void printInfo(void);

private:
	double reactance;
};

/*********************************
	CIRCUIT CLASS DEFINITION
*********************************/
class CIRCUIT
{
public:
	
	// constructor and destructor
	CIRCUIT();
	virtual ~CIRCUIT();
	
	// set and get functions for private member frequency
	void setFrequency(double initFrequency) { frequency = initFrequency; }
	double getFrequency() { return frequency; }
	
	// set and get for resistor (not a pointer)
	void setResistor(RESISTOR initResistor) { resistor = initResistor; }
	RESISTOR getResistor() { return resistor; }
	
	// set and get for inductor (pointer)
	void setInductor(INDUCTOR* initInductor) { inductor = initInductor; }
	INDUCTOR* getInductor() { return inductor; }
	
	// printInfo function
	void printInfo(void);

private:
	double frequency;
	RESISTOR resistor;  // object gets created automatically
	INDUCTOR* inductor; // object does not get created automatically
};

#endif
