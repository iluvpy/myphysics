#include <SFML/Graphics.hpp>
#include "Shapes.hpp"
#include "Time.hpp"
#include "Keyboard.hpp"

int main() {
    sf::RenderWindow window(sf::VideoMode(800, 600), "Hello SFML");
    sf::Color backgroundColor = sf::Color::White;
    
    Rectangle rect(100, 100, 10, 10, sf::Color::Red);
    rect.addForceY(980);

    Circle circle(200, 200, 100);
    TimeHandler tHandler(600);
    Keyboard keyboard;

    int frame = 0;
    while (window.isOpen()) {
        tHandler.startFrame();
        keyboard.clear();
        sf::Event event;
        while (window.pollEvent(event)) {
            if (event.type == sf::Event::Closed) {
                window.close();
            }
            if (event.type == sf::Event::KeyPressed) {
                keyboard.press(event.key.code);
            } 
            else if (event.type == sf::Event::KeyReleased) {
                keyboard.release(event.key.code);
            }
        } 

        window.clear(backgroundColor);
        
        // draw
        window.draw(rect.getDrawable());
        window.draw(circle.getDrawable());

        // update
        rect.update(tHandler.getDeltaT());

        window.display();
        tHandler.waitForNextFrame();
        tHandler.endFrame();
        frame++;
    }

    return 0;
}