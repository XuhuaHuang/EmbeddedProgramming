/*****************************************************************//**
 * \file   circuit.cpp
 * \brief  Contains all function definitions
 * excluding one-line functions
 * one-liner function have been defined in place with classes
 *
 * \author Xuhua Huang
 * \date   December 2020
 *********************************************************************/

#include "circuit.hpp"

 /*************************************
     COMPONENT CLASS CONSTRUCTORS
 **************************************/
COMPONENT::COMPONENT() // default constructor
{
    std::cout << "\n[DECONST]COMPONENT" << "\n";
    setValue(0.00);
}

COMPONENT::COMPONENT(double initValue) // overloaded constructor
{
    std::cout << "\n[OLCONST]COMPONENT" << "\n";
    setValue(initValue);
}

void COMPONENT::printInfo(void)
{
    std::cout << "\n[fn][COMPONENT]Private member \'value\' = " << getValue();
    return;
}

/***************************************
    RESISTOR CLASS MEMBER FUNCTIONS
****************************************/
RESISTOR::RESISTOR() // default constructor
{
    // expecting base class COMPONENT default constructor called
    std::cout << "\n[DFCONST]RESISTOR" << "\n"
        << "[DFCONST][RESISTOR]Expecting base class COMPONENT default constructor called" << "\n";
    setPowerRating(0.00);
}

RESISTOR::RESISTOR(double initValue, double initPowerRating) : COMPONENT(initValue)
{
    // expecting base class COMPONENT overloaded constructor called
    std::cout << "\n[OLCONST]RESISTOR" << "\n"
        << "[OLCONST][RESISTOR]Expecting base class COMPONENT overloaded constructor called" << "\n"
        << "[OLCONST][RESISTOR]Invoking mutator for private member \'powerRating\'." << "\n";
    setPowerRating(initPowerRating);
}

void RESISTOR::printInfo(void)
{
    std::cout << "\n[fn][RESISTOR]Invoking base class \'COMPONENT\' printInfo function." << "\n";
    COMPONENT::printInfo();
    // appending unit 'Ohms' at the end
    std::cout << " Ohms" << "\n";

    std::cout << "[fn][RESISTOR]Private member \'powerRating\' = " << std::fixed
        << getPowerRating() << " W" << "\n";
}

/***************************************
    INDUCTOR CLASS MEMBER FUNCTIONS
****************************************/
INDUCTOR::INDUCTOR() : COMPONENT(0.00047) // default constructor pass 0.00047 henry
{
    std::cout << "\n[DECONST]INDUCTOR" << "\n"
        << "[DFCONST][INDUCTOR]Expecting base class COMPONENT default constructor called" << "\n"
        << "[DFCONST][INDUCTOR]Called base class overloaded constructor" << "\n";
    setReactance(0.00);
}

INDUCTOR::~INDUCTOR() // destructor
{
    std::cout << "\n[DESTRUCT][INDUCTOR]Destructing object of class \'INDUCTOR\' >_<" << "\n";
}

void INDUCTOR::calcReactance(double frequency) // default argument removed
{
    std::cout << "\n[fn][INDUCTOR]calcReactance" << "\n";
    setReactance(2 * PI * frequency * getValue());
}

void INDUCTOR::printInfo(void)
{
    std::cout << "\n[fn][INDUCTOR]Invoking base class \'COMPONENT\' printInfo function." << "\n";
    COMPONENT::printInfo();
    // appending unit 'H' at the end
    std::cout << " H" << "\n"
        << "[fn][INDUCTOR]Private member \'reactance\' = " << getReactance() << " Ohms" << "\n";
}

/***************************************
    CIRCUIT CLASS MEMBER FUNCTIONS
****************************************/
CIRCUIT::CIRCUIT()
{
    std::cout << "\n[DFCONST]CIRCUIT" << "\n"
        << "[DFCONST][CIRCUIT]A pointer to an INDUCTOR object is created" << "\n"
        << "[DFCONST][CIRCUIT]Expecting class INDUCTOR default constructor called" << "\n";
    setFrequency(10000);
    setInductor(new INDUCTOR);
}

CIRCUIT::~CIRCUIT()
{
    std::cout << "\n[DESTRUCT]CIRCUIT" << "\n"
        << "[DESTRUCT][CIRCUIT]Dedicated pointer to an INDUCTOR object is deleted" << "\n"
        << "[DESTRUCT][CIRCUIT]Expecting class INDUCTOR destructor called" << "\n";
    delete inductor;
}

void CIRCUIT::printInfo(void)
{
    std::cout << "\n[fn][CIRCUIT]printInfo" << "\n"
        << "[fn][CIRCUIT]Circuit frequency = " << getFrequency() << " Hz" << "\n"
        << "[fn][CIRCUIT]Invoking printInfo for class RESISTOR and INDUCTOR" << "\n";
    (getResistor()).printInfo();
    (getInductor())->printInfo(); // getInductor() returns a pointer
}
