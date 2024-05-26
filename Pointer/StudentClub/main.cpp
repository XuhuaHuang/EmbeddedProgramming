/*****************************************************************//**
 * \file   main.cpp
 * \brief  Pointer Lab Main Function
 *
 * Notice: ALL "std::cout" statements inside a function are appened
 * after signature "[fn]" which stands for printing from function
 *
 * [DECONST] printed from default constructor
 * [OLCONST] printed from overloaded constructor
 * [DEST] printed from destructor
 *
 * \author Xuhua Huang
 * \date   November 11, 2020
 *********************************************************************/

#include <iostream>
#include <string>
#include <time.h>

#include "Student.hpp"
#include "StudentClub.hpp"
#include "Numbers.hpp"

int main(void)
{
    //Student* student = new Student("Charlie", "Accounting");
    //std::cout << student->getName() << "\n";
    //std::cout << student->getMajor() << "\n";
    //delete student;

    std::cout << "\nTeating class \"StudentClub\"." << "\n";
    Student* student1 = new Student("Angela", "Medicine");
    // student1 is linked to Angela

    Student* student2 = new Student("Carmen", "Business");
    // student2 is linked to Carmen

    Student* student3 = new Student("George", "Engineering");
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

    std::cout << "\nVerifying student club members in \"HeritageClub\"..." << "\n"
        << "The president is: " << HeritageClub.getPresident()->getName() << "\n"
        << "The vice president is: " << HeritageClub.getVicePresident()->getName() << "\n"
        << "The secretary is: " << HeritageClub.getSecretary()->getName() << "\n"
        << "The treasurer is: " << HeritageClub.getTreasurer()->getName() << "\n";
    // equivalent to: ... << ( *HeritageClub.getPresident() ).getName() << ...
    //                ... <<              ...getVicePresident().getName() << ...

    // craeting an object of class 'Number'
    Numbers numObject1(10); // using the overloaded constructor to set the size to 10

    int index = 0; // index
    srand(time(NULL)); // seed of the rendom number generator
    double randomVal; // random number that gets overwritten as loop increments

    while (index < numObject1.getSize()) // putting ten random number to the array
    {
        randomVal = rand() % 100 + 1.00; // 1.00 cast the variable to double
        // std::cout << randomVal << "\n"; // comment out this line if you do not need to troubleshoot
        numObject1.store(index, randomVal);
        index++;
    }
    std::cout << "Ten random numbers has been added to the array called \"numObject1\"." << "\n";

    index = 0; // reuse the variable declared before and overwrite with a new value
    double retrievedVal = 0;
    while (index < numObject1.getSize()) // putting ten random number to the array
    {
        retrievedVal = numObject1.retrieve(index); // passing the index to retrieve the value stored in the array
        std::cout << "The latest sequencially retrieved value in the array is: " << retrievedVal << "\n";
        index++;
    }

    // calculate the average of all ten numbers in numObject1
    double averageObj1 = numObject1.average();
    std::cout << "The average of the array called \"numObject1\" is: " << averageObj1 << "\n";

    delete student1; delete student2; delete student3; // releasing memory

    return 0;
}
