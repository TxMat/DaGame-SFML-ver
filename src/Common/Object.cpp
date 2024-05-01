//
// Created by uranus on 4/24/24.
//

#include "Object.h"

#include <utility>

Object::Object(sf::Shape *mShape, std::string Name) : m_shape(mShape), m_name(std::move(Name)) {

}

sf::Shape *Object::getMShape() const {
    return m_shape;
}

void Object::Update() {
//    m_shape->rotate(5.0f);
}

bool Object::CheckCollision(Object* other) {
    // Implement narrow-phase collision detection between this object and another object
    // Return true if collision detected, false otherwise
    return m_shape->getGlobalBounds().intersects(other->m_shape->getGlobalBounds());
}

void Object::HandleCollision(Object* other) {
    // Handle collision response between this object and another object
}
