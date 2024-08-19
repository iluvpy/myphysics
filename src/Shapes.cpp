#include "Shapes.hpp"

void PhysicalObject::updateVelocity(float deltaT) {
    velocity.x += acceleration.x * deltaT / 1e6;
    velocity.y += acceleration.y * deltaT / 1e6;
    velocity *= m_friction;
}

void PhysicalObject::update(sf::Vector2f &pos, float deltaT) {
    updateVelocity(deltaT);
    updatePos(pos, deltaT);
}

void PhysicalObject::updatePos(sf::Vector2f& pos, float deltaT) {
    pos.x += velocity.x * deltaT / 1e6;
    pos.y += velocity.y * deltaT / 1e6;
}

void Rectangle::update(float deltaT) {
    sf::Vector2f pos = m_rectangle.getPosition();
    PhysicalObject::update(pos, deltaT);
    m_rectangle.setPosition(pos);
}
