/*
* Author: Xuhua Huang
* Teacher: Charmaine
* Pointer Lab Function Definitions
*
* Contains function definitions of 'Pointer_lab.h'
*
* Notice: ALL "cout" statements inside a function are appened
* after signature "[fn]" which stands for printing from function
* [DECONST] printed from default constructor
* [OLCONST] printed from overloaded constructor
* [DEST] printed from destructor
*/

#include <iostream>
#include <string>
#include "Pointer_lab.h" // dedicated library

using namespace std;

// class 'Student'
Student::Student() // default constructor
{
	cout << "\n[DECONST]Creating an empty object of class \"Student\"." << endl;
	name = "";
	major = "";
}

Student::Student(string student_name, string major_at_acceptance) // overloaded constructor
{
	cout << "\n[OLCONST]\"Student::Student(string, string)\" called by compiller" << endl
		<< "[OLCONST]Setting name to: " << student_name << endl
		<< "[OLCONST]Setting major to: " << major_at_acceptance << endl;
	name = student_name;
	major = major_at_acceptance;
}

// class 'StudentClub'
StudentClub::~StudentClub()
{
	cout << "\n[DEST]Destructing...Deleting all club members..." << endl;
	
	President = NULL;
	VicePresident = NULL;
	Secretary = NULL;
	Treasurer = NULL;

	cout << "[DEST]Done. All members of club erased." << endl;
}

// class 'Numbers'
Numbers::Numbers(int sizeofArray) // overloaded constructor with signed cout statements
{
	setSize(sizeofArray);
	ptrNumber = new double[getSize()];	
	
	cout << "\n[OLCONST]\"Numbers::Numbers(int) is called by compiller." << endl
		 << "[OLCONST]Size of array noe set to: " << getSize() << endl
		 << "[OLCONST]Pointer to array initialized." << endl;
}

Numbers::~Numbers()
{
	cout << "\n[DEST]Destructing...Deleting array pointer..." << endl;
	
	delete ptrNumber;
	
	cout << "[DEST]Done. Array pointer erased." << endl;
}

void Numbers::store(int arrayIndex, double numToAdd)
{
	*(ptrNumber + arrayIndex) = numToAdd;

	cout << "\n[fn]New element added to index: " << arrayIndex << endl
		 << "[fn]Content of added element: " << numToAdd << endl;

	return;
}

double Numbers::retrieve(int arrayIndex)
{
	double value = *(ptrNumber + arrayIndex);
	
	cout << "\n[fn]Retreiving element at index: " << arrayIndex << endl
		 << "[fn]Content of retreived element: " << value << endl;
	
	return value;
}

double Numbers::average()
{
	double sum = 0; 
	for (int i = 0; i < getSize(); i++)
	{
		cout << "\n[fn]Retrieving element indexed: " << i << " from the average() function";
		sum += retrieve(i);
	}
	double result = sum / getSize();

	return result;
}
