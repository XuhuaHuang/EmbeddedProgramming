/*
* Author: Xuhua Huang
* Teacher: Charmaine
* Pointer Lab Main Function
*
* Contains main function of 'Pointer_lab.h'
*
* Notice: ALL "cout" statements inside a function are appened
* after signature "[fn]" which stands for printing from function
* [DECONST] printed from default constructor
* [OLCONST] printed from overloaded constructor
* [DEST] printed from destructor
*/

#include <iostream>
#include <string>
#include <time.h>
#include "Pointer_lab.h" // dedicated library

using namespace std;

int main(void)
{
	/*
	* Student* student = new Student("Charlie", "Accounting");
	* cout << student->getName() << endl;
	* cout << student->getMajor() << endl;
	*
	* delete student;
	*/
	
	cout << "\nTeating class \"StudentClub\"." << endl;
	Student* student1 = new Student("Angela", "Medicine");
	// student1 is linked to Angela

	Student* student2 = new Student("Carmen", "Business");
	// student2 is linked to Carmen

	Student* student3 = new Student("George", "Engineeringn");
	// student3 is linked to Geoge

	// declare a StudentClub object
	StudentClub HeritageClub;

	//Set Angela as the president
	HeritageClub.setPresident(student1);

	//Set Carmen as the vice - president
	HeritageClub.setVicePresident(student2);

	//Set George as both the Secretary and Treasurer
	HeritageClub.setSecretary(student3);
	HeritageClub.setTreasurer(student3);

	cout << "\nVerifying student club members in \"HeritageClub\"..." << endl
		 << "The president is: " << HeritageClub.getPresident()->getName() << endl
		 << "The vice president is: " << HeritageClub.getVicePresident()->getName() << endl
		 << "The secretary is: " << HeritageClub.getSecretary()->getName() << endl
		 << "The treasurer is: " << HeritageClub.getTreasurer()->getName() << endl;
	// equivalent to: ... << ( *HeritageClub.getPresident() ).getName() << ...
	//				  ... <<				 ...VicePresident()...		<< ...

	// craeting an object of class 'Number'
	Numbers numObject1(10); // using the overloaded constructor to set the size to 10

	int index = 0; // index
	srand(time(NULL)); // seed of the rendom number generator
	double randomVal; // random number that gets overwritten as loop increments
	
	while (index < numObject1.getSize()) // putting ten random number to the array
	{
		randomVal = rand() % 100 + 1.00; // 1.00 cast the variable to double
		// cout << randomVal << endl; // comment out this line if you do not need to troubleshoot
		numObject1.store(index, randomVal);
		index++;
	}
	cout << "Ten random numbers has been added to the array called \"numObject1\"." << endl;

	index = 0; // reuse the variable declared before and overwrite with a new value
	double retrievedVal = 0;
	while (index < numObject1.getSize()) // putting ten random number to the array
	{
		retrievedVal = numObject1.retrieve(index); // passing the index to retrieve the value stored in the array
		cout << "The latest sequencially retrieved value in the array is: " << retrievedVal << endl;
		index++;
	}

	// calculate the average of all ten numbers in numObject1
	double averageObj1 = numObject1.average();
	cout << "The average of the array called \"numObject1\" is: " << averageObj1 << endl;

	return 0;
}
