#include <SFML/Graphics.hpp>

int main() {
    sf::RenderWindow window(sf::VideoMode(500, 500), "Hello SFML");
    sf::Color backgroundColor = sf::Color::White;

    while (window.isOpen()) {
        sf::Event event;
        while (window.pollEvent(event)) {
            if (event.type == sf::Event::Closed)
                window.close();
        }

        window.clear(backgroundColor);


        window.display();
    }

    return 0;
}