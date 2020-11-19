/*
* 1879700 Xuhua Huang
* Inheritance Lab Part 2 Main File
*
* Contains:
* main function
* - Test cases for each class
*
* Notice: when executing, "cout" are printed without signatures
* "cout" statements with signature "[fn]" come from functions
* If not specified, default constructors are called
*/

// built-in library:
#include <iostream>
#include <math.h>
#include <string>
#include <Windows.h>
//#include <iomanip>
//#include <float.h>

// customized class:
#include "Inheritance_relatives_header.h"

/*
* Class name:
* Grandfather - base
* Father - first-level derived
* Son - second-level derived
*/ 

using namespace std;

int main(void)
{
	//Testing Grandfather class
	Grandfather myGrandfather1;
	// verify cout statements with '[DFCONST]' printed from default constructor
	
	cout << "\033[1;32m" // change colour to green
		 << "\nTesting \"Grandfather\" class..." << endl	
		 << "Object \"myGrandfather1\" is created with default constructor." << endl
		 << "Verify statement printed with [DFCONST] signature." << endl
		 << "The name for \"myGrandfather1\" is: " << myGrandfather1.getName() << endl
		 << "And \"myGrandfather1\" is born in: " << myGrandfather1.getYearBorn() << endl;

	// creating another object of class 'Grandfather'
	Grandfather myGrandfather2("Edward", 1940);
	// verify cout statements with '[OLCONST]' printed from overloaded constructor

	cout << "\nObject \"myGrandfather2\" is created with overloaded constructor." << endl
		 << "Verify statement printed with [OLCONST] signature from two classes." << endl
		 << "The name for \"myGrandfather2\" is: " << myGrandfather2.getName() << endl
		 << "And \"myGrandfather2\" is born in: " << myGrandfather2.getYearBorn() << endl;

	cout << "\nTest cases for class \"Grandfather\" end here.\n" << endl
		 << "\033[0m" // reset colour to white
		 << "****************************************************************************************************************" << endl;

	// Testing Father class
	// creating an object from class 'Father'
	Father myFather1; 

	cout << "\033[1;36m" // change colour to cyan
		 << "\nTesting \"Father\" class..." << endl
		 << "Object \"myFather1\" is created with default constructor." << endl
		 << "Verify statement printed with [DFCONST] signature." << endl
		 << "Occupation for \"myFather1\" is: " << myFather1.getOccupation() << endl
		 << "Name for \"myFather1\" is: " << myFather1.getName() << endl
		 << "And \"myFather1\" is born in: " << myFather1.getYearBorn() << endl;

	// creating another object from class 'Father'
	// added variable occupation
	Father myFather2("Accountant", "Henry", 1980);

	cout << "\nObject \"myFather2\" is created with overloaded constructor." << endl
		 << "Verify statement printed with [OLCONST] signature from two classes." << endl
		 << "Occupation for \"myFather2\" is: " << myFather2.getOccupation() << endl
		 << "Name for \"myFather2\" is: " << myFather2.getName() << endl
		 << "And \"myFather2\" is born in: " << myFather2.getYearBorn() << endl;

	cout << "\nTest cases for class \"Father\" end here.\n" << endl
		 << "\033[0m" // reset colour to white
		 << "****************************************************************************************************************" << endl;

	// Testing Son class
	// added variable 'schoolYear[int]'
	// creating an object from class 'Son'
	Son mySon1;

	cout << "\033[1;34m" // change colour to blue
		 << "\nTesting \"Son\" class..." << endl
		 << "Object \"mySon1\" is created with default constructor." << endl
		 << "Verify statement printed with [DFCONST] signature." << endl
		 << "School year is: " << mySon1.getSchoolYear() << endl
		 << "Occupation for \"mySon1\" is: " << mySon1.getOccupation() << endl
		 << "Name for \"mySon1\" is: " << mySon1.getName() << endl
		 << "And \"mySon1\" is born in: " << mySon1.getYearBorn() << endl;

	/*
	* for mySon1, update the information
	* change value with set functions
	* name: Paul
	* born year: 2008
	* occupation: student
	* school year : 6
	*/
	
	cout << "\nUpdating name, born year, occupation and school year..." << endl
		 << "Information should be updated to: " << endl
		 << "\tname: Paul\n\tborn in: 2008\n\toccupation: student\n\tschool year: 6" << endl;
	
	mySon1.setName("Paul");
	mySon1.setYearBorn(2008);
	mySon1.setOccupation("student");
	mySon1.setSchoolYear(6);

	// verify updated information:
	cout << "\nChecking updated result:" << endl
		 << "Name for \"mySon1\" is updated to: " << mySon1.getName() << endl
		 << "Born year for \"mySon1\" is updated to: " << mySon1.getYearBorn() << endl
		 << "Occupation for \"mySon1\" is updated to: " << mySon1.getOccupation() << endl
		 << "School year for \"mySon1\" is updated to: " << mySon1.getSchoolYear() << endl;
		 
	cout << "\nTest cases for class \"Son\" end here.\n" << endl
		 << "\033[0m" // reset colour to white
		 << "****************************************************************************************************************" << endl;
	
	return 0;
}
