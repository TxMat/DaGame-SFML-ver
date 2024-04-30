//
// Created by uranus on 4/24/24.
//

#include "Object.h"

Object::Object(sf::Shape *mShape) : m_shape(mShape) {

}

sf::Shape *Object::getMShape() const {
    return m_shape;
}

void Object::Update() {
//    m_shape->rotate(5.0f);
}
