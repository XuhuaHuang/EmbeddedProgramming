/*****************************************************************//**
 * \file   AngryBirds.hpp
 * \brief  class declaration AngryBirds and function prototype.
 *
 * \author Xuhua Huang
 * \date   September 2020
 *********************************************************************/

#define PI 3.14159365359
#define G 9.81

class AngryBirds
{
private:
    double initVel;
    double angle;
    double initHeight;

    double horiVel;
    double vertiVel;

    double travelTime;
    double distance;
    double maxHeight;

public:
    // mutators
    inline void setVel(double vel) { this->initVel = vel; }
    inline void setAngle(double angle) { this->angle = angle; }
    inline void setinitHeight(double initHeight) { this->initHeight = initHeight; }

    inline void setVx(double vx) { this->horiVel = vx; }
    inline void setVy(double vy) { this->vertiVel = vy; }

    inline void setTime(double travelTime) { this->travelTime = travelTime; }
    inline void setDistance(double distance) { this->distance = distance; }
    inline void setHeight(double maxheight) { this->maxHeight = maxheight; }

    // accessors
    double getVel() { return initVel; }
    double getAngle() { return angle; }
    double getinitHeight() { return initHeight; }

    double getVx() { return horiVel; }
    double getVy() { return vertiVel; }

    double getTime() { return travelTime; }
    double getDistance() { return distance; }
    double getmaxHeight() { return maxHeight; }

    // initialize and print function prototype
    void initialize();
    void printParameter();

    // different calculation function prototype
    void calcVx();
    void calcVy();
    void calcT();
    void calcRange();
    void calcHmax();

};
