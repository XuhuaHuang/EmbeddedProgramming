/*****************************************************************//**
 * \file   Student.hpp
 * \brief  Pointer Lab Header File - class Student
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


#ifndef STUDENT_HPP
#define STUDENT_HPP

#ifndef _IOSTREAM_
#include <iostream>
#endif

#include <string>

class Student
{
public:
    Student(); // default constructor
    Student(std::string student_name, std::string major_at_acceptance); // overloaded constructor

    // set and get functions
    void setMajor(std::string new_major) { major = new_major; }
    void setName(std::string new_name) { name = new_name; }
    std::string getMajor() { return major; }
    std::string getName() { return name; }

private:
    std::string name;
    std::string major;
};

Student::Student() // default constructor
{
    std::cout << "\n[DECONST]Creating an empty object of class \"Student\"." << "\n";
    name = "";
    major = "";
}

Student::Student(std::string student_name, std::string major_at_acceptance) // overloaded constructor
{
    std::cout << "\n[OLCONST]\"Student::Student(std::string, std::string)\" called by compiller" << "\n"
        << "[OLCONST]Setting name to: " << student_name << "\n"
        << "[OLCONST]Setting major to: " << major_at_acceptance << "\n";
    name = student_name;
    major = major_at_acceptance;
}

#endif
