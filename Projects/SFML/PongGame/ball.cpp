#include "ball.h"

// part 1
// This the constructor and it is called when we create an object
// X.H. added the third argument to set texture
Ball::Ball(float startX, float startY, Texture *texture) 
{
    position.x = startX;
    position.y = startY;
 
    ballShape.setSize(sf::Vector2f(20, 20)); // X.H.doubled the size
    ballShape.setPosition(position);
    
    ballShape.setTexture(texture); // X.H. added this line
}

// part 2
// // all other function definitions
FloatRect Ball::getPosition()
{
    return ballShape.getGlobalBounds();
}
 
RectangleShape Ball::getShape()
{
    return ballShape;
}
 
float Ball::getXVelocity()
{
    return xVelocity;
}
 
void Ball::reboundSides()
{
    xVelocity = -xVelocity;
}
 
void Ball::reboundBatOrTop()
{
    position.y -= (yVelocity * 30);
    yVelocity = -yVelocity;
 
}
 
void Ball::hitBottom()
{
    position.y = 1;
    position.x = 500;
}
 
void Ball::update()
{
    // Update the ball position variables
    position.y += yVelocity;
    position.x += xVelocity;
 
    // Move the ball and the bat
    ballShape.setPosition(position);
}
