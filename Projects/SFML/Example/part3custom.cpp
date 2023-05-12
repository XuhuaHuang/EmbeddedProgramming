#include <SFML/Graphics.hpp>

int main()
{
    // Make a window that is 800 by 200 pixels
    // And has the title "Hello from SFML"
    sf::RenderWindow window(sf::VideoMode(1600, 400), "GoodBye from Bob");
    // X.H. changed the title of the window to "GoodBye from Bob"

    // Create a "Text" object called "message".
    sf::Text message;

    // Select a font
    sf::Font font;
    // font.loadFromFile("28_Days_Later.ttf"); // X.H. commented out this line
    // font.loadFromFile("arial.ttf"); // X.H. added extra comment for an option
    font.loadFromFile("OpenSans-Regular.ttf"); // X.H. changed the font of the message

    // Set the font to our message
    message.setFont(font);

    // Assign the actual message
    message.setString("Xuhua Huang"); // X.H. modified the content of the message to "Xuhua Huang"

    // Set the size
    message.setCharacterSize(200); // X.H. changed the size from 100 to 200

    // Choose a color
    sf::Color col(
        0, 0, 255); // X.H. changed the color of the txt from (255, 255, 255) to (0, 0, 255) which is dark blue

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
    } // This is the end of the "while" loop

    return 0;
}
