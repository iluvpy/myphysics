#pragma once
#include <iostream>
#include <SFML/Graphics.hpp>


#define DEFAULT_COLOR sf::Color::Black


class PhysicalObject {
private: 
    sf::Vector2f velocity;
    sf::Vector2f acceleration;
    
protected:

    inline void updateVelocity(float deltaT) {velocity += acceleration * deltaT;} 
    inline void updatePos(sf::Vector2f& pos, float deltaT) {
        pos.x += velocity.x * deltaT;
        pos.y += velocity.y * deltaT;
    }

public:

    inline void addForceX(float force) {acceleration.x += force;}
    inline void addForceY(float force) {acceleration.y += force;}
    void update(sf::Vector2f& pos, float deltaT);
};

class Circle : public PhysicalObject{
private:
    sf::CircleShape m_circle;

public:
    Circle(double x, double y, double radius, sf::Color color=DEFAULT_COLOR) {
        m_circle.setPosition(sf::Vector2f(x, y));
        m_circle.setRadius(radius);
        m_circle.setFillColor(color);
    }
    inline const sf::Drawable& getDrawable() {return m_circle;}

};

class Rectangle : public PhysicalObject{
private:
    sf::RectangleShape m_rectangle;

public:
    Rectangle(double x, double y, double width, double height, const sf::Color& color=DEFAULT_COLOR) {
        m_rectangle.setPosition(sf::Vector2f(x, y));
        m_rectangle.setSize(sf::Vector2f(width, height));
        m_rectangle.setFillColor(color);
    }
    
    inline const sf::Drawable& getDrawable() {return m_rectangle;}
    void update(float dT) {

    }
};

// TODO: Triangles, for now i'll only work with rects and circles
// class Triangle {
// private:
//     sf::ConvexShape m_triangle;
// public:
//     // x,y: position of center
//     Triangle(double x, double y, double base, double height) {
//         m_triangle.setPointCount(3);
//     }
//     void draw(sf::RenderWindow& window);

// };
