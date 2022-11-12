/*****************************************************************//**
 * \file   GamePromotion_main.cpp
 * \brief  contains example test cases for base class 'Game'
 * 
 * \author Xuhua Huang
 * \date   December 2020
 *********************************************************************/

#include <iostream>
#include <string>
#include "GamePromotion.h"

int main(void)
{
    // Testing base class Game
    // test default constructor
    std::cout << "\nTesting base class Game with default constructor" << "\n";
    Game myGame{};
    std::cout << "Default name = " << myGame.getName() << "\n";

    // testing overloaded constructor with initial name
    std::cout << "\nTesting base class Game with overloaded constructor" << "\n";
    Game myGame2 { "Hide and Seek" };
    std::cout << "Name for myGame2 = " << myGame2.getName() << "\n";

    // testing Game class printInfo function
    myGame2.printInfo();

    std::cout << "\nPress Enter to continue..." << "\n";
    std::cin.get();
    return 0;
}
