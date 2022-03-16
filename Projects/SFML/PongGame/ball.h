#pragma once
#include <SFML/Graphics.hpp>
 
using namespace sf;
 
class Ball
{
private:
    Vector2f position;
 
    // A RectangleShape object called ref
    RectangleShape ballShape;
 
    float xVelocity = .2f;
    float yVelocity = .2f;
 
public:
    Ball(float startX, float startY, Texture *texture);
 
    FloatRect getPosition();
 
    RectangleShape getShape();
 
    float getXVelocity();
 
    void reboundSides();
 
    void reboundBatOrTop();
 
    void hitBottom();
 
    void update();
 
};
