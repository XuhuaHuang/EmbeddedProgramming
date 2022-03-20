//1879700 Xuhua Huang

#include <iostream>
#include <cmath>
using namespace std;

#define PI 3.14159365359
#define G 9.81

typedef struct angryBirds
{
	double initVel;
	double angle;
	double iniHeight;

	double horizVel;
	double vertiVel;

	double travelTime;
	double distance;
	double maxHeight;

} ANGBIRD;


void initialize(ANGBIRD* ab);
void printParameter(ANGBIRD ab);

void setBird(ANGBIRD* ab, double userv, double userangle, double userheight);

void calcVx(ANGBIRD* ab);
void calcVy(ANGBIRD* ab);
void calcT(ANGBIRD* ab);
void calcRange(ANGBIRD* ab);
void calcHmax(ANGBIRD* ab);


int main(void)
{

	ANGBIRD userPlay; // declare a variable belongs to this structure

	double userv;
	double userangle;
	double userheight; // these three variable must be provided

	/*
	double vx;
	double vy;
	double timeofFlight;
	double distance;
	double maximumHeight; // these variables are going to be calculated
	*/

	cout << "\nInitializing..." << endl;
	initialize(&userPlay);

	printParameter(userPlay);

	cout << "\n\nYou are about to launch your bird and beat the pigs up." << endl;
	cout << "Please enter the initial velocity below:" << endl;
	cin >> userv;

	cout << "Please enter the angle above or below the horizon of the trajectory motion:" << endl;
	cin >> userangle;

	cout << "Please enter the initial height at which your bird is about to launch:" << endl;
	cin >> userheight;


	setBird(&userPlay, userv, userangle, userheight);

	calcVx(&userPlay);
	calcVy(&userPlay);
	calcT(&userPlay);
	calcRange(&userPlay);
	calcHmax(&userPlay);

	printParameter(userPlay);


	return 0;
}


void initialize(ANGBIRD* ab)
{

	ab->initVel = 0.0;
	ab->angle = 0.0;

	ab->horizVel = 0.0;
	ab->vertiVel = 0.0;

	ab->distance = 0.0;
	ab->maxHeight = 0.0;
	ab->travelTime = 0.0;

	return;
}


void printParameter(ANGBIRD ab)
{

	cout << "\nTrajectory information provided is listed as the following:\n" << endl;
	cout << "The initial velocity set is: " << ab.initVel << " m/s." << endl;
	cout << "The angle of the trajectory motion (in degrees) is: " << ab.angle << " degrees." << endl;

	cout << "\nAs a result,\n\tthe horizontal velocity is: " << ab.horizVel << " m/s." << endl;
	cout << "\tthe vertical velocity is: " << ab.vertiVel << " m/s." << endl;

	cout << "\nThe maximum horizontal displacement of this bird is: " << ab.distance << " m." << endl;
	cout << "The maximum height the bird reached is: " << ab.maxHeight << " m." << endl;
	cout << "The total travel time in the air is: " << ab.travelTime << " s." << endl;
	cout << "List of specs end here." << endl;

	return;
}

void setBird(ANGBIRD* ab, double userv, double userangle, double userheight)
{

	ab->initVel = userv;
	ab->angle = userangle;
	ab->iniHeight = userheight;

	return;
}

void calcVx(ANGBIRD* ab)
{

	ab->horizVel = ab->initVel * cos(ab->angle * PI / 180);
	//cout << "The horizal velocity is: " << ab->horizVel << endl;

	return;
}


void calcVy(ANGBIRD* ab)
{

	ab->vertiVel = ab->initVel * sin(ab->angle * PI / 180);
	//cout << "The vertical velocity is: " << ab->vertiVel << endl;

	return;
}


void calcT(ANGBIRD* ab)
{

	ab->travelTime = (1 / G) * (ab->vertiVel + sqrt(pow(ab->vertiVel, 2) + 2 * G * ab->iniHeight));
	//cout << "The travel time is: " << ab->travelTime << endl;

	return;
}


void calcRange(ANGBIRD* ab)
{

	ab->distance = ab->horizVel * ((1 / G) * (ab->vertiVel + sqrt(pow(ab->vertiVel, 2) + 2 * G * ab->iniHeight)));
	//cout << "The horizal displacement is: " << ab->distance << endl;

	return;
}


void calcHmax(ANGBIRD* ab)
{

	ab->maxHeight = ab->iniHeight + pow(ab->vertiVel, 2) / (2 * G);
	//cout << "The maximum height is: " << ab->maxHeight << endl;

	return;
}
