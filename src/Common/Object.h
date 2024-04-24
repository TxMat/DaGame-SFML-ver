//
// Created by uranus on 4/24/24.
//

#include "SFML/Graphics.hpp"

#ifndef CMAKESFMLPROJECT_OBJECT_H
#define CMAKESFMLPROJECT_OBJECT_H


class Object {

public:
    explicit Object(sf::Vector2f vector);

    [[nodiscard]] sf::RectangleShape *getMShape() const;

    void setMShape(sf::RectangleShape *mShape);

private:

    sf::RectangleShape* m_shape;

};


#endif //CMAKESFMLPROJECT_OBJECT_H
