#include <SFML/Graphics.hpp>

int main() {
    // Create a window with a size of 500x500 pixels and a title "Hello SFML"
    sf::RenderWindow window(sf::VideoMode(500, 500), "Hello SFML");

    // Set the background color to white
    sf::Color backgroundColor = sf::Color::White;

    // Run the main loop
    while (window.isOpen()) {
        // Process events
        sf::Event event;
        while (window.pollEvent(event)) {
            // Close window: exit
            if (event.type == sf::Event::Closed)
                window.close();
        }

        // Clear the window with the background color
        window.clear(backgroundColor);

        // Draw everything here...

        // Display the contents of the window
        window.display();
    }

    return 0;
}