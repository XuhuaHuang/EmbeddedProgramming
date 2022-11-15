/*****************************************************************//**
 * \file   StudentClub.hpp
 * \brief  Pointer Lab Header File - class StudentClub
 *
 * Notice: all "cout" statements inside a function are appened
 * after signature "[fn]" which stands for printing from function
 *
 * [DECONST] printed from default constructor
 * [OLCONST] printed from overloaded constructor
 * [DEST] printed from destructor
 *
 * \author Xuhua Huang
 * \date   November 11, 2020
 *********************************************************************/

#ifndef STUDENTCLUB_HPP
#define STUDENTCLUB_HPP

#ifndef STUDENT_HPP
#include "Student.hpp"
#endif

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

StudentClub::~StudentClub()
{
    std::cout << "\n[DEST]Destructing...Deleting all club members..." << "\n";

    President = NULL;
    VicePresident = NULL;
    Secretary = NULL;
    Treasurer = NULL;

    std::cout << "[DEST]Done. All members of club erased." << "\n";
}

#endif
