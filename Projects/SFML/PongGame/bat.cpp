#include "bat.h"

// part 1
// This the constructor and it is called when we create an object
Bat::Bat(float startX, float startY)
{
    position.x = startX;
    position.y = startY;
 
    batShape.setSize(sf::Vector2f(100, 10)); // X.H. doubled the size
    batShape.setPosition(position);
}

// part 2
// all other function definitions
FloatRect Bat::getPosition()
{
    return batShape.getGlobalBounds();
}
 
RectangleShape Bat::getShape()
{
    return batShape;
}
 
void Bat::moveLeft()
{
    position.x -= batSpeed;
}
 
void Bat::moveRight()
{
    position.x += batSpeed;
}
 
void Bat::update()
{
    batShape.setPosition(position);
}
