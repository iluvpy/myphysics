#pragma once
#include <iostream>
#include <SFML/Graphics.hpp>

#include "Util.hpp"

#define DEFAULT_COLOR sf::Color::Black


class PhysicalObject {
private: 
    sf::Vector2f velocity;
    sf::Vector2f acceleration;
    float m_friction = 1.0f;
protected:

    void updateVelocity(float deltaT);
    void updatePos(sf::Vector2f& pos, float deltaT);

public:

    inline void addForceX(float force) {acceleration.x += force;}
    inline void addForceY(float force) {acceleration.y += force;}
    inline void setVelocityX(float vx) { velocity.x = vx; }
    inline void setVelocityY(float vy) { velocity.y = vy; }
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
    void update(float deltaT);
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
