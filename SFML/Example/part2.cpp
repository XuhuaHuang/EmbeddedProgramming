Thanks to: Charmaine Jirgens
Teacher at Electronics and Information Technology at Heritage College, Gatineau, Quebec, Canada

#include <SFML/Audio.hpp>
#include <SFML/Graphics.hpp>

int main()
{
    int sts = EXIT_SUCCESS;

    // Create the main window
    sf::RenderWindow window(sf::VideoMode(800, 600), "SFML window");
   
    // Load a sprite to display
    sf::Texture texture;
   
    if (!texture.loadFromFile("star_wars.jpg"))
        sts = EXIT_FAILURE;
    sf::Sprite sprite(texture);
   
    // Create a graphical text to display
    sf::Font font;
   
    if (!font.loadFromFile("arial.ttf"))
        sts = EXIT_FAILURE;
   
    sf::Text text("Hello war from Xuhua", font, 50);
   
    // Load a music to play
    sf::Music music;
   
    if (!music.openFromFile("Horror-Pattern.wav"))
        sts = EXIT_FAILURE;
   
    // Play the music
    // music.initialize(); // told to initialize it first
    music.play();
    music.setVolume(100); // set to volume to Max
    music.setLoop(true); // loop "Horror-Pattern.ogg"
   
    // Start the game loop
    while (window.isOpen())
    {
        // Process events
        sf::Event event;
        while (window.pollEvent(event))
        {
            // Close window: exit
            if (event.type == sf::Event::Closed)
                window.close();
        }
        // Clear screen
        window.clear();
        // Draw the sprite
        window.draw(sprite);
        // Draw the string
        window.draw(text);
        // Update the window
        window.display();
    }
    
    return sts;
}
