/*****************************************************************//**
 * \file   Relatives.cpp
 * \brief  Inheritance Lab Part 2 Function File
 * 
 * Contains:
 * default / overloaded constructors
 * funtion definitions
 * 
 * Notice: ALL "cout" statements inside a function are appened
 * after signature "[fn]" which stands for printing from function
 * [DECONST] printed from default constructor
 * [OLCONST] printed from overloaded constructor
 * 
 * \author Xuhua Huang
 * \date   November 19, 2020
 *********************************************************************/

// built-in library:
#include <iostream>
#include <math.h>
#include <string>
#include <Windows.h>

// customized class:
#include "Relatives.hpp"

using std::cout;

// Base class 'Grandfather' function definitions:
Grandfather::Grandfather()
{
    setName("GrandPa");
    setYearBorn(1930);

    cout << "\n[DFCONST]Default constructor \"Grandfather::Grandfather()\" is called." << "\n"
         << "[DFCONST]The name is initialized to \"GrandPa\" and born year initialized to 1930." << "\n"
         << "[DFCONST]Default constructor \"Grandfather::Grandfather()\"ends executing on this line." << "\n";
}

Grandfather::Grandfather(string initName, int initYearBorn)
{
    setName(initName);
    setYearBorn(initYearBorn);

    cout << "\n[OLCONST]Overloaded constructor \"Grandfather::Grandfather(string, int)\" is called with valid parameters." << "\n"
         << "[OLCONST]Name is initialized to: " << initName << "\n" 
         << "[OLCONST]Born year initialized to: " << initYearBorn << "\n"
         << "[OLCONST]Overloaded constructor \"Grandfather::Grandfather(string, int)\"ends executing on this line." << "\n";
}

// First-level derived class 'Father' function definitions:
Father::Father()
{
    // using set functions to initialize varialbes:
    setName("Dad");
    setYearBorn(1970);
    setOccupation("Engineer");

    cout << "\n[DFCONST]Default constructor \"Father::Father()\" is called." << "\n"
         << "[DFCONST]The name is initialized to \"Dad\" and born year initialized to 1970." << "\n"
         << "[DFCONST]The occupation iinitialized to \"engineer\"." << "\n"
         << "[DFCONST]Default constructor \"Father::Father()\"ends executing on this line." << "\n";
}

Father::Father(string initOccupation, string initName, int initYearBorn) : Grandfather(initName, initYearBorn)
{
    setOccupation(initOccupation); // using set function for variable occupation
    // initName and initYearBorn are passed to 'Grandfather' class overloaded constructor

    cout << "\n[OLCONST]Overloaded constructor \"Father::Father(string, string, int)\" is called with valid parameters." << "\n"
         << "[OLCONST]Occupation is initialized to: " << initOccupation << "\n"
         << "[OLCONST]Name is initialized to: " << initOccupation << "\n"
         << "[OLCONST]Born year initialized to: " << initYearBorn << "\n"
         << "[OLCONST]Overloaded constructor \"Father::Father(string, string, int)\"ends executing on this line." << "\n";
}
