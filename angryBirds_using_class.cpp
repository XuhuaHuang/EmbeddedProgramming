#include <iostream>
#include <cmath>

using namespace std;

#define PI 3.14159365359
#define G 9.81

class angrybirds
{
	
	private:
		double iniVel;
		double angle;
		double iniHeight;
		
		double horiVel;
		double vertiVel;
	
		double travelTime;
		double distance;
		double maxHeight;
		
	public:
		// set funtions:
		void setVel (double userv){iniVel = userv;}
		void setAngle (double userangle) {angle = userangle;}
		void setiniHeight (double useriniheight) {iniHeight = useriniheight;}
		
		void setVx (double calVx) {horiVel = calVx;}
		void setVy (double calVy) {vertiVel = calVy;}
	
		void setTime (double usertime) {travelTime = usertime;}
		void setDistance (double userdistance) {distance = userdistance;}
		void setHeight (double usermaxheight) {maxHeight  = usermaxheight;}
		// all set functions end here
		
		// get functions:
		double getVel() {return iniVel;}
		double getAngle() {return angle;}
		double getiniHeight() {return iniHeight;}
		
		double getVx() {return horiVel;}
		double getVy() {return vertiVel;}
		
		double getTime() {return travelTime;}
		double getDistance () {return distance;}
		double getmaxHeight() {return maxHeight;}
		// all set funtions end here
		
		// initialize and print function prototype		
		void initialize();
		void printParameter();
		
		// different calculation function prototype:
		void calcVx();
		void calcVy();
		void calcT();
		void calcRange();
		void calcHmax();
		
} ANGBIRD;


int main (void)
{
	
	angrybirds userplay;
	
	double userv;
	double userangle;
	double userheight;
	
	cout << "\nInitializing..." << endl;
	
	userplay.initialize();
	userplay.printParameter();
	
	cout << "\n\nYou are about to launch your bird and beat the pigs up." << endl;
	cout << "Please enter the initial velocity below:" << endl;
	cin >> userv;
	
	cout << "Please enter the angle above or below the horizon of the trajectory motion:" << endl;
	cin >> userangle;
	
	cout << "Please enter the initial height at which your bird is about to launch:" << endl;
	cin >> userheight;
	
	userplay.setVel(userv);
	userplay.setAngle(userangle);
	userplay.setHeight(userheight);
	
	userplay.calcVx();
	userplay.calcVy();
	userplay.calcT();
	userplay.calcRange();
	userplay.calcHmax();
	
	userplay.printParameter();
	
	return 0;
}


void angrybirds::initialize()
{
	
	iniVel = 0.0;
	angle = 0.0;
	iniHeight = 0.0;
	
	horiVel = 0.0;
	vertiVel = 0.0;
	
	travelTime = 0.0;
	distance = 0.0;
	maxHeight = 0.0;
	
	return;
}


void angrybirds::printParameter()
{
	
	cout << "\nTrajectory information provided is listed as the following:\n" << endl;
	cout << "The initial velocity set is: " << getVel() << " m/s." << endl;
	cout << "The angle of the tracjectory motion (in degrees) is: " << getAngle() << " degrees." << endl;
	
	cout << "\nAs a result,\n\tthe horizontal velocity is: " << getVx() << " m/s." << endl;
	cout << "\tthe vertical velocity is: " << getVy() << " m/s." << endl;
	
	cout << "\nThe maximum horizontal displacement of this bird is: " << getDistance() << " m." << endl;
	cout << "The maximum height the bird reached is: " << getmaxHeight() << " m." << endl;
	cout << "The total travel time in the air is: " << getTime() << " s." << endl;
	cout << "List of specs end here." << endl;
	
	return;
}


void angrybirds::calcVx()
{
	setVx( getVel() * cos(getAngle() * PI/180) );
	return;
}

void angrybirds::calcVy()
{
	setVy( getVel() * sin(getAngle() * PI/180) ); 
	return;
}


void angrybirds::calcT()
{
	setTime( (1/G) * (getVy() + sqrt(pow(getVy(), 2)+2*G*getiniHeight())) );
	return;
}


void angrybirds::calcRange()
{
	setDistance( getVx() * ((1/G) * (  getVy() + sqrt(pow(getVy(), 2)+2*G*getiniHeight()))) );	
	return;
}


void angrybirds::calcHmax()
{
	setHeight( getiniHeight() + pow(getVy(), 2) / (2*G) );
	return;
}
