#include "Shapes.hpp"

void PhysicalObject::update(sf::Vector2f &pos, float deltaT) {
    updateVelocity(deltaT);
    updatePos(pos, deltaT);
}
