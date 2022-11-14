/*****************************************************************//**
 * \file   AngryBirds.cpp
 * \brief  AngryBirds struct function definitions.
 * 
 * \author Xuhua Huang
 * \date   September 2020
 *********************************************************************/

#include <iostream>
#include "AngryBirds.h"

void initialize(AngryBirds* bird)
{
    bird->initVel = 0.0;
    bird->angle = 0.0;

    bird->horizVel = 0.0;
    bird->vertiVel = 0.0;

    bird->distance = 0.0;
    bird->maxHeight = 0.0;
    bird->travelTime = 0.0;

    return;
}


void printParameter(const AngryBirds bird)
{
    std::cout << "\nTrajectory information provided is listed as the following:\n" << "\n";
    std::cout << "The initial velocity set is: " << bird.initVel << " m/s." << "\n";
    std::cout << "The angle of the trajectory motion (in degrees) is: " << bird.angle << " degrees." << "\n";

    std::cout << "\nAs a result,\n\tthe horizontal velocity is: " << bird.horizVel << " m/s." << "\n";
    std::cout << "\tthe vertical velocity is: " << bird.vertiVel << " m/s." << "\n";

    std::cout << "\nThe maximum horizontal displacement of this bird is: " << bird.distance << " m." << "\n";
    std::cout << "The maximum height the bird reached is: " << bird.maxHeight << " m." << "\n";
    std::cout << "The total travel time in the air is: " << bird.travelTime << " s." << "\n";
    std::cout << "List of specs end here." << "\n";

    return;
}

void setBird(AngryBirds* bird, double userv, double userangle, double userheight)
{
    bird->initVel = userv;
    bird->angle = userangle;
    bird->iniHeight = userheight;

    return;
}

void calcVx(AngryBirds* bird)
{
    bird->horizVel = bird->initVel * cos(bird->angle * PI / 180);
    //std::cout << "The horizal velocity is: " << bird->horizVel << "\n";

    return;
}


void calcVy(AngryBirds* bird)
{
    bird->vertiVel = bird->initVel * sin(bird->angle * PI / 180);
    //std::cout << "The vertical velocity is: " << bird->vertiVel << "\n";

    return;
}


void calcT(AngryBirds* bird)
{
    bird->travelTime = (1 / G) * (bird->vertiVel + sqrt(pow(bird->vertiVel, 2) + 2 * G * bird->iniHeight));
    //std::cout << "The travel time is: " << bird->travelTime << "\n";

    return;
}


void calcRange(AngryBirds* bird)
{
    bird->distance = bird->horizVel * ((1 / G) * (bird->vertiVel + sqrt(pow(bird->vertiVel, 2) + 2 * G * bird->iniHeight)));
    //std::cout << "The horizal displacement is: " << bird->distance << "\n";

    return;
}


void calcHmax(AngryBirds* bird)
{
    bird->maxHeight = bird->iniHeight + pow(bird->vertiVel, 2) / (2 * G);
    //std::cout << "The maximum height is: " << bird->maxHeight << "\n";

    return;
}
