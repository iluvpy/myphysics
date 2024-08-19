#include <SFML/Graphics.hpp>
#include "Shapes.hpp"
#include "Time.hpp"

int main() {
    sf::RenderWindow window(sf::VideoMode(800, 600), "Hello SFML");
    sf::Color backgroundColor = sf::Color::White;
    
    Rectangle rect(100, 100, 100, 100, sf::Color::Red);
    rect.addForceX(1000);

    Circle circle(200, 200, 100);
    TimeHandler tHandler(600);
    int frame = 0;
    while (window.isOpen()) {
        tHandler.startFrame();
        sf::Event event;
        while (window.pollEvent(event)) {
            if (event.type == sf::Event::Closed)
                window.close();
        } 

        window.clear(backgroundColor);
 
        window.draw(rect.getDrawable());
        window.draw(circle.getDrawable());

        rect.update(tHandler.getDeltaT());

        window.display();
        tHandler.waitForNextFrame();
        tHandler.endFrame();
        if (frame % 100 == 0) {
            std::cout << "avg frames: " << tHandler.getAverageFrameRate() << std::endl;
            std::cout << "avg delta T / 1e6: " << tHandler.getAverageDT() / 1e6 << std::endl;
        }
        frame++;
    }

    return 0;
}