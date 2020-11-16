/*
* Author: Xuhua Huang
* Teacher: Charmaine
* Pointer Lab Header File
*
* Contains declaration of:
* class 'Student'
* class
* class
*	- constructor and destructor
*
* Notice: ALL "cout" statements inside a function are appened
* after signature "[fn]" which stands for printing from function
* [DECONST] printed from default constructor
* [OLCONST] printed from overloaded constructor
* [DEST] printed from destructor
*/

#include <iostream>
#include <string>

using namespace std;

class Student
{
public:

	Student(); // default constructor
	Student(string student_name, string major_at_acceptance); // overloaded constructor

	// set and get functions
	void setMajor(string new_major) { major = new_major; }
	void setName(string new_name) { name = new_name; }
	string getMajor() { return major; }
	string getName() { return name; }

private:
	string name;
	string major;;
};

class StudentClub
{
public:

	// desturctor
	~StudentClub();

	// set and get functions:
	void setPresident(Student* newPresident) { President = newPresident; }
	Student* getPresident() { return President; }

	void setVicePresident(Student* newVicePresident) { VicePresident = newVicePresident; }
	Student* getVicePresident() { return VicePresident; }

	void setSecretary(Student* newSecretary) { Secretary = newSecretary; }
	Student* getSecretary() { return Secretary; }

	void setTreasurer(Student* newTreasurer) { Treasurer = newTreasurer; }
	Student* getTreasurer() { return Treasurer; }

private:

	Student* President, * VicePresident, * Secretary, * Treasurer;
};

class Numbers
{
public:

	// set and get functions:
	void setSize(int newSize) { size = newSize; }
	int getSize() { return size; }

	void setPtrNum(double* newPtrNum) { ptrNumber = newPtrNum; }
	double* getPtrNum() { return ptrNumber; }

	// overloaded constructor and destructor:
	Numbers(int sizeOfArray); // overloaded constructor
	~Numbers();

	void store(int arrayIndex, double numToAdd);
	double retrieve(int arrayIndex);
	double average();

private:

	int size;
	double* ptrNumber;
};
