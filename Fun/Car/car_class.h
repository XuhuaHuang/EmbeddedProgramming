#include <string>

using namespace  std;

class mapCoordinate
{
private:
	int x;
	int y;

public:
	void setX(int userX) { x = userX; }
	int getX() { return x; }

	void setY(int userY) { x = userY; }
	int getY() { return y; }

	mapCoordinate();
	mapCoordinate(int initX, int initY);

};

class car
{
private:
	string brand;
	bool ignitionState;
	bool stop;
	string directionControl;
	bool obstacleDetect;
	double speed;
	double acceleration;
	bool autoPilot;
	int speedLimit;

	mapCoordinate currentCoordinate;

public:
	void setBrand(string userBrand) { brand = userBrand; }
	string getBrand() { return brand; }

	void setIgnitionState(bool userIgnition) { ignitionState = userIgnition; }
	bool getIgnitionState() { return ignitionState; }

	void setStop(bool userStop) { stop = userStop; }
	bool getStop() { return stop; }

	void setDirection(string userDirection) { directionControl = userDirection; }
	string getDirection() { return directionControl; }

	void setObstacle(bool userObstacle) { obstacleDetect = userObstacle; }
	bool getObstacle() { return obstacleDetect; }

	void setSpeed(double userSpeed) { speed = userSpeed; }
	double getSpeed() { return speed; }

	void setAcceleration(double userAcceleration) { acceleration = userAcceleration; }
	double getAcceleration() { return acceleration; }

	void setAutoPilot(bool userAutoPilot) { autoPilot = userAutoPilot; }
	bool getAutoPilot() { return autoPilot; }

	void setSpeedLimit(int userSpeedLimit) { speedLimit = userSpeedLimit; }
	int getSpeedLimit() { return speedLimit; }

	void setCurrentCoordinate(mapCoordinate userCoordinate) { currentCoordinate = userCoordinate; }
	mapCoordinate getCurrentCoordinate() { return currentCoordinate; }


	car();
	car(string brand, bool iginitionState, string directionControl, double speed);

	void displayHelpMenu();
	void displayStatus(car userCar);

	void autoPilot(car userCar, mapCoordinate destination, double arriveInMins);
};

class racingCar : public car
{
private:
	double rimRadius;
	double horsePower;
	bool turble;
	bool aeroDynamic;

public:

};

class FormulaOne : public racingCar
{
private:
	double fuelLevel;
	bool needRepair;
	bool safetyCar;
	string coachCommand;
	string componentDefective;

public:

};
