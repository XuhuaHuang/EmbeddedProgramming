/*****************************************************************//**
 * \file   test_is_instance_of.cpp
 * \brief  Demonstration of library code in ".\util\is_instance_of.hpp"
 * 
 * Command used to compile:
 * $ g++ -o is_instance.exe .\test_is_instance_of.cpp -std=c++11
 * $ .\is_instance.exe
 * 
 * \author Xuhua Huang
 * \date   October 2021
 *********************************************************************/

#include <iostream>
#include <stdlib.h>
#include "is_instance_of.hpp"

class Parent {};
class Child : Parent {};
class Unrelated {};

int main(void)
{
    Child* c;

    /* Check c is an instance of class Child. */
    if (util::type::is_instance_of<Child>(c)) {
        std::cout << "Object c is instance of Child class" << "\n";
    }
    else {
        std::cout << "Object c is not instance of Child class" << "\n";
    }

    /* Check c is an instance of class Parent. */
    if (util::type::is_instance_of<Parent>(c)) {
        std::cout << "Object c is instance of Parent class" << "\n";
    }
    else {
        std::cout << "Object c is not instance of Parent class" << "\n";
    }

    /* Check c is an instance of class AnotherClass. */
    if (util::type::is_instance_of<Unrelated>(c)) {
        std::cout << "Object c is instance of AnotherClass class" << "\n";
    }
    else {
        std::cout << "Object c is not instance of AnotherClass class" << "\n";
    }

    system("pause");
    return 0;
}
