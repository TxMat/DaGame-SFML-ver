//
// Created by uranus on 4/24/24.
//

#include "SFML/Graphics.hpp"

#ifndef CMAKESFMLPROJECT_OBJECT_H
#define CMAKESFMLPROJECT_OBJECT_H


class Object {

public:
    explicit Object(sf::Shape *mShape, std::string Name);

    virtual ~Object() = default;

    virtual void Update() = 0;

    [[nodiscard]] sf::Shape *getMShape() const;

    virtual bool CheckCollision(Object *other);

    virtual void HandleCollision(Object *other);

protected:

    sf::Shape *m_shape;

    std::string m_name;
};


#endif //CMAKESFMLPROJECT_OBJECT_H
