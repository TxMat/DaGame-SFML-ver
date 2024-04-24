//
// Created by uranus on 4/24/24.
//

#include "Object.h"

sf::RectangleShape *Object::getMShape() const {
    return m_shape;
}

void Object::setMShape(sf::RectangleShape *mShape) {
    m_shape = mShape;
}

Object::Object(sf::Vector2f vector) {
    m_shape = new sf::RectangleShape(vector);
}
