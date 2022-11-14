/*****************************************************************//**
 * \file   angryBirds_structure.cpp
 * \brief  Introduction to Object-Oriented Programming using class
 * to program a preliemanery Angry Birds game core logic (projectile motion)
 *
 * \author Xuhua Huang
 * \date   September 2020
 *********************************************************************/

#include "AngryBirds.hpp"

#ifndef _IOSTREAM_
#include <iostream>
#endif

#ifndef _CMATH_
#include <cmath>
#endif

int main(void)
{
    AngryBirds bird;

    double userv;
    double userangle;
    double userheight;

    std::cout << "\nInitializing..." << "\n";

    bird.initialize();
    bird.printParameter();

    /* Ask the user to enter initial parameters. */
    std::cout << "\n\nYou are about to launch your bird and beat the pigs up." << "\n";
    std::cout << "Please enter the initial velocity below:" << "\n";
    std::cin >> userv;

    std::cout << "Please enter the angle above or below the horizon of the trajectory motion:" << "\n";
    std::cin >> userangle;

    std::cout << "Please enter the initial height at which your bird is about to launch:" << "\n";
    std::cin >> userheight;

    /* Call set functions to set attributes and sanitize user inputs. */
    bird.setVel(userv);
    bird.setAngle(userangle);
    bird.setHeight(userheight);

    /* Call calculation functions to obtain data. */
    bird.calcVx();
    bird.calcVy();
    bird.calcT();
    bird.calcRange();
    bird.calcHmax();

    /* Print simulation output. */
    bird.printParameter();

    return EXIT_SUCCESS;
}
