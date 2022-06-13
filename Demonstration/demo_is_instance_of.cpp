/*****************************************************************//**
 * \file   demo_is_instance_of.cpp
 * \brief  Demonstration of library code in ".\util\is_instance.h"
 * 
 * Command used to compile:
 * $ g++ -o is_instance.exe .\demo_is_instance.cpp -std=c++11
 * $ .\is_instance.exe
 * 
 * \author Xuhua Huang
 * \date   October 2021
 *********************************************************************/

#include <iostream>
#include <stdlib.h>
#include "../Util/is_instance_of.h"

class Parent {};
class Child : Parent {};
class AnotherClass {};

int main(void)
{
    Child* c;

    /* Check c is an instance of class Child. */
    if (util::type::is_instance_of<Child>(c)) {
        std::cout << "Object c is instance of Child class" << std::endl;
    }
    else {
        std::cout << "Object c is not instance of Child class" << std::endl;
    }

    /* Check c is an instance of class Parent. */
    if (util::type::is_instance_of<Parent>(c)) {
        std::cout << "Object c is instance of Parent class" << std::endl;
    }
    else {
        std::cout << "Object c is not instance of Parent class" << std::endl;
    }

    /* Check c is an instance of class AnotherClass. */
    if (util::type::is_instance_of<AnotherClass>(c)) {
        std::cout << "Object c is instance of AnotherClass class" << std::endl;
    }
    else {
        std::cout << "Object c is not instance of AnotherClass class" << std::endl;
    }

	system("pause");
	return 0;
}