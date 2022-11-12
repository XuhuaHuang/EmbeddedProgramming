#pragma once
#include <SFML/Graphics.hpp>

using namespace sf;

class Bat
{
private:
    Vector2f position;
 
    // A RectangleShape object
    RectangleShape batShape;
 
    float batSpeed = .3f;
 
public:
    Bat(float startX, float startY);
 
    FloatRect getPosition();
 
    RectangleShape getShape();
 
    void moveLeft();
 
    void moveRight();
 
    void update();
 
};
