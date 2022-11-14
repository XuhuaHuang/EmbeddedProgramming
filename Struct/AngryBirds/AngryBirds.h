/*****************************************************************//**
 * \file   AngryBirds.h
 * \brief  struct declaration AngryBirds and function prototype.
 *
 * \author Xuhua Huang
 * \date   September 2020
 *********************************************************************/

#define PI 3.14159365359
#define G 9.81

typedef struct AngryBirds
{
    double initVel;
    double angle;
    double iniHeight;

    double horizVel;
    double vertiVel;

    double travelTime;
    double distance;
    double maxHeight;

} AngryBirds;


void initialize(AngryBirds* bird);
void printParameter(const AngryBirds bird);

void setBird(AngryBirds* bird, double userv, double userangle, double userheight);

void calcVx(AngryBirds* bird);
void calcVy(AngryBirds* bird);
void calcT(AngryBirds* bird);
void calcRange(AngryBirds* bird);
void calcHmax(AngryBirds* bird);
