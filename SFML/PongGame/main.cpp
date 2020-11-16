#include "bat.h"
#include "ball.h"
#include <sstream>
#include <cstdlib>
#include <SFML/Graphics.hpp>
 
// Avoid having to put sf in front of all the SFML classes and functions
using namespace sf;

// This is where our game starts from
int main()
{
    int windowWidth = 1024;
    int windowHeight = 768;
    // Make a window that is 1024 by 768 pixels
    // And has the title "Pong"
    RenderWindow window(VideoMode(windowWidth, windowHeight), "Pong");

    int score = 0;
    int lives = 5;

    // create a bat
    Bat bat (windowWidth / 2, windowHeight - 20);

	// X.H. created a texture with the following lines:
	Texture texture;
	texture.loadFromFile("golf.jpg"); // X.H. load from image file named "golf.jpg"
	
    // create a ball
    Ball ball(windowWidth / 2, 1, &texture);

	// Create a "Text" object called "message". Weird but we will learn about objects soon
	Text hud;

	// We need to choose a font
	Font font;
	font.loadFromFile("DS-DIGIT.ttf");

	// Set the font to our message
	hud.setFont(font);

	// Make it really big
	hud.setCharacterSize(75);

	// Choose a color
	hud.setFillColor(sf::Color::Green); // X.H. changed color from "White" to "Green"

	while (window.isOpen())
	{
		// Handle the player input
 
		Event event;
		while (window.pollEvent(event))
		{
			if (event.type == Event::Closed) // Someone closed the window- bye
				window.close();
		}
 
		if (Keyboard::isKeyPressed(Keyboard::Left)) // move left...
		{
        
			bat.moveLeft();
		}
		else if (Keyboard::isKeyPressed(Keyboard::Right))
		{
			// move right...
			bat.moveRight();
		}
		else if (Keyboard::isKeyPressed(sf::Keyboard::Escape))
		{
			// quit...
			// Someone closed the window- bye
			window.close();
		}
    
		// Update the frame
		// Handle ball hitting the bottom
		if (ball.getPosition().top > windowHeight)
		{
			// reverse the ball direction
			ball.hitBottom();
	
			// Remove a life
			lives --;

			// Check for zero lives
			if (lives < 1)
			{
				// reset the score
				score = 0;
				// reset the lives
				lives = 5;
			}
		}

		// Handle ball hitting top
		if (ball.getPosition().top < 0)
		{
			ball.reboundBatOrTop();
			// Add a point to the players score
			score++;
		}

		// Handle ball hitting sides
		if (ball.getPosition().left < 0 || ball.getPosition().left + 10 > windowWidth)
		{
			ball.reboundSides();
		}

		// Has the ball hit the bat?
		if (ball.getPosition().intersects(bat.getPosition()))
		{
			// Hit detected so reverse the ball and score a point
			ball.reboundBatOrTop();
		}

		ball.update();
		bat.update();

		// Update the HUD text
		std::stringstream ss;
		ss << "Score:" << score << "    Lives:" << lives;
		hud.setString(ss.str());

		// Draw the frame
		// Clear everything from the last frame
		window.clear(Color(128, 128, 182, 255));
		// X.H. changed the color
		window.draw(bat.getShape());
		window.draw(ball.getShape());
		// Draw our score
		window.draw(hud);

		// Show everything we just drew
		window.display();
		
	}// This is the end of the "while" loop

    
	return 0;

}
