#include "carClass.h"
#include <iostream>
#include <string>

using namespace std;

mapCoordinate::mapCoordinate()
{
	setX(0);
	setY(0);
}

mapCoordinate::mapCoordinate(int initX, int initY)
{
	setX(initX);
	setY(initY);
}

car::car()
{

}

car::car(string userBrand, bool userIginitionState, string userDirection, double userSpeed)
{

}

void car::displayHelpMenu()
{

	return;
}

void car::displayStatus(car userCar)
{ 
	cout << "Ignition state: " << userCar.getIgnitionState() << endl
		 << "Current Speed: " << userCar.getSpeed() << " KM/h." << endl
		 << "Speed limit: " << userCar.getSpeedLimit() << " KM/h." << endl
		 << "Current direction: " << userCar.getDirection() << endl
		 << "Current X coordinate: " << (userCar.getCurrentCoordinate()).getX() << endl
		 << "Current Y coordinate: " << (userCar.getCurrentCoordinate()).getY() << endl
		 << "Current auto pilot status: " << userCar.getAutoPilot() << endl;
	
	return;
}

void car::autoPilot(car userCar, mapCoordinate destination, double arriveInMins)
{
	mapCoordinate current = userCar.getCurrentCoordinate();

	int differenceX = destination.getX() - current.getX();

	int differenceY = destination.getY() - current.getY();

	double distance = sqrt(differenceX ^ 2 + differenceY ^ 2);

	if ( (distance / userCar.getSpeed() ) > arriveInMins)
	{
		bool speeding;
		
		int newSpeed;
		cout << "You need to go faster." << endl
			 << "Please enter a higher speed:";
		cin >> newSpeed;
		
		do
		{
			speeding = false;

			if (newSpeed > userCar.getSpeedLimit())
			{
				speeding = true;
				cout << "You are speeding." << endl
					 << "Please enter a new speed: " << endl;
				cin >> newSpeed;
			}
			else
			{
				cout << "Valid speed." << endl
					 << "Setting new speed..." << endl;
				userCar.setSpeed(newSpeed);
			}
		} while (speeding);

	}
	userCar.displayStatus(userCar);

	return;
}
