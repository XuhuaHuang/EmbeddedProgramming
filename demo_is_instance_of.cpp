/*****************************************************************//**
 * \file   demo_is_instance_of.cpp
 * \brief  
 * 
 * \author Xuhua Huang
 * \date   October 2021
 *********************************************************************/

#include <iostream>
#include "Util/is_instance_of.h"
#include <stdlib.h>

class Parent {};
class Child : Parent {};
class AnotherClass {};

int main(void)
{
    Child* c;

    /* Check c is an instance of Child. */
    if (util::type::is_instance_of<Child>(c)) {
        std::cout << "c is instance of Child class" << std::endl;
    }
    else {
        std::cout << "c is not instance of Child class" << std::endl;
    }

    /* Check c is an instance of Parent. */
    if (util::type::is_instance_of<Parent>(c)) {
        std::cout << "c is instance of Parent class" << std::endl;
    }
    else {
        std::cout << "c is not instance of Parent class" << std::endl;
    }

    /* Check c is an instance of AnotherClass. */
    if (util::type::is_instance_of<AnotherClass>(c)) {
        std::cout << "c is instance of AnotherClass class" << std::endl;
    }
    else {
        std::cout << "c is not instance of AnotherClass class" << std::endl;
    }

	system("pause");
	return 0;
}