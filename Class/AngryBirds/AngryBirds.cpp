/*****************************************************************//**
 * \file   AngryBirds.cpp
 * \brief  AngryBirds struct function definitions.
 *
 * \author Xuhua Huang
 * \date   September 2020
 *********************************************************************/

#include <iostream>
#include <cmath>
#include "AngryBirds.hpp"

void AngryBirds::initialize()
{
    initVel = 0.0;
    angle = 0.0;
    initHeight = 0.0;

    horiVel = 0.0;
    vertiVel = 0.0;

    travelTime = 0.0;
    distance = 0.0;
    maxHeight = 0.0;

    return;
}


void AngryBirds::printParameter()
{
    std::cout << "\nTrajectory information provided is listed as the following:\n" << "\n";
    std::cout << "The initial velocity set is: " << getVel() << " m/s." << "\n";
    std::cout << "The angle of the trajectory motion (in degrees) is: " << getAngle() << " degrees." << "\n";

    std::cout << "\nAs a result,\n\tthe horizontal velocity is: " << getVx() << " m/s." << "\n";
    std::cout << "\tthe vertical velocity is: " << getVy() << " m/s." << "\n";

    std::cout << "\nThe maximum horizontal displacement of this bird is: " << getDistance() << " m." << "\n";
    std::cout << "The maximum height the bird reached is: " << getmaxHeight() << " m." << "\n";
    std::cout << "The total travel time in the air is: " << getTime() << " s." << "\n";
    std::cout << "List of specs end here." << "\n";

    return;
}


void AngryBirds::calcVx()
{
    setVx(getVel() * cos(getAngle() * PI / 180));
    return;
}

void AngryBirds::calcVy()
{
    setVy(getVel() * sin(getAngle() * PI / 180));
    return;
}


void AngryBirds::calcT()
{
    setTime((1 / G) * (getVy() + sqrt(pow(getVy(), 2) + 2 * G * getinitHeight())));
    return;
}


void AngryBirds::calcRange()
{
    setDistance(getVx() * ((1 / G) * (getVy() + sqrt(pow(getVy(), 2) + 2 * G * getinitHeight()))));
    return;
}


void AngryBirds::calcHmax()
{
    setHeight(getinitHeight() + pow(getVy(), 2) / (2 * G));
    return;
}
