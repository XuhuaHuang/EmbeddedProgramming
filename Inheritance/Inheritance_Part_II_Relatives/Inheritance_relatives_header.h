/*
* 1879700 Xuhua Huang
* Inheritance Lab Part 2 Header File
*
* Contains declaration of:
* Base Class 'Grandfather'
* Derived Class 'Father'
* Derived Class 'Son'
*/

#include <string>
using namespace std; // or use 'std::string'

// Base class 'Grandfather'
class Grandfather
{
private:
	string name;
	int yearBorn;

public:

	// default and overloaded constructor
	Grandfather();
	Grandfather(string initName, int initYearBorn);

	// set and get function for variable 'name[string]'
	void setName(string userName) { name = userName; }
	string getName() { return name; }

	// set and get function for variable 'yearBorn[int]'
	void setYearBorn(int userYearBorn) { yearBorn = userYearBorn; }
	int getYearBorn() { return yearBorn; }
};

// First-level derived class 'Father'
class Father : public Grandfather
{
private:
	string occupation;

public:
	
	// default and overloaded constructor
	Father();
	Father(string initOccupation, string initName, int initYearBorn);

	// set and get function for variable 'occupation[string]'
	void setOccupation(string userOccupation) { occupation = userOccupation; }
	string getOccupation() { return occupation; }
};

// Second-level derived class 'Son'
class Son : public Father
{
private:
	int schoolYear;

public:

	// set and get function for variable 'schoolYear[int]'
	void setSchoolYear(int userSchoolYear) { schoolYear = userSchoolYear; }
	int getSchoolYear() { return schoolYear; }
};
