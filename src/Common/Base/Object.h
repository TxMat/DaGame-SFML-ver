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

    virtual void Update(float deltaTime) = 0;

    [[nodiscard]] sf::Shape *getMShape() const;

    virtual bool CheckCollision(Object *other);

    virtual void HandleCollision(Object *other);

    bool b_shouldGenerateHits = false;

    bool b_isColliding = false;

    std::vector<Object *> m_HitList;

    bool b_shouldHandleCollision = false;

    sf::Vector2f m_normalized_speed_vector = sf::Vector2f(0.0f, 0.0f);
    sf::Vector2f m_forward_vector = sf::Vector2f(0.0f, 0.0f);

protected:

    sf::Shape *m_shape;
    std::string m_name;
};


#endif //CMAKESFMLPROJECT_OBJECT_H
