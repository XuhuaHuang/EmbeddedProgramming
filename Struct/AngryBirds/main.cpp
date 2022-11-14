/*****************************************************************//**
 * \file   angryBirds_structure.cpp
 * \brief  Introduction to Object-Oriented Programming using struct
 * to program a preliemanery Angry Birds game core logic (projectile motion)
 *
 * \author Xuhua Huang
 * \date   September 2020
 *********************************************************************/

#include <iostream>
#include "AngryBirds.h"

int main(void)
{
    AngryBirds bird; // declare a variable belongs to this structure

    double initVelocity;
    double initAngle;
    double initHeight; // these three variable must be provided

    // these variables are going to be calculated
    //double vx;
    //double vy;
    //double timeofFlight;
    //double distance;
    //double maximumHeight;

    std::cout << "\nInitializing..." << "\n";
    initialize(&bird);

    printParameter(bird);

    std::cout << "\n\nYou are about to launch your bird and beat the pigs up." << "\n";
    std::cout << "Please enter the initial velocity below:" << "\n";
    std::cin >> initVelocity;

    std::cout << "Please enter the angle above or below the horizon of the trajectory motion:" << "\n";
    std::cin >> initAngle;

    std::cout << "Please enter the initial height at which your bird is about to launch:" << "\n";
    std::cin >> initHeight;


    setBird(&bird, initVelocity, initAngle, initHeight);

    calcVx(&bird);
    calcVy(&bird);
    calcT(&bird);
    calcRange(&bird);
    calcHmax(&bird);

    printParameter(bird);

    return EXIT_SUCCESS;
}
