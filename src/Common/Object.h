//
// Created by uranus on 4/24/24.
//

#include "SFML/Graphics.hpp"

#ifndef CMAKESFMLPROJECT_OBJECT_H
#define CMAKESFMLPROJECT_OBJECT_H


class Object {

public:
    explicit Object(sf::Shape *mShape);

    [[nodiscard]] sf::Shape *getMShape() const;

protected:

    sf::Shape* m_shape;

};


#endif //CMAKESFMLPROJECT_OBJECT_H
