Thanks to: Charmaine Jirgens
Teacher at Electronics and Information Technology at Heritage College, Gatineau, Quebec, Canada

// This includes code from the SFML library
#include <SFML/Graphics.hpp>
 
int main()
{
    // Make a window that is 800 by 200 pixels
    // And has the title "Hello from SFML"
    sf::RenderWindow window(sf::VideoMode(800, 200), "Hello from SFML");
 
    // Create a "Text" object called "message".
    sf::Text message;
 
    // Select a font
    sf::Font font;
    font.loadFromFile("28_Days_Later.ttf");
 
    // Set the font to our message
    message.setFont(font);
 
    // Assign the actual message
    message.setString("Hello world");
 
    // Set the size
    message.setCharacterSize(100);
 
    // Choose a color
    sf::Color col(255, 255, 255);
    message.setFillColor(col);
   
 
    // This "while" loop goes round and round- perhaps forever
    while (window.isOpen())
    {
        // The next 6 lines of code detect if the window is closed
        // And then shuts down the program
        sf::Event event;
        while (window.pollEvent(event))
        {
            if (event.type == sf::Event::Closed)
                // Someone closed the window- bye
                window.close();
        }
 
        // Clear everything from the last run of the while loop
        window.clear();
 
        // Draw our message
        window.draw(message);
 
        // Show everything we just drew
        window.display();
    }// This is the end of the "while" loop
 
    return 0;
}
