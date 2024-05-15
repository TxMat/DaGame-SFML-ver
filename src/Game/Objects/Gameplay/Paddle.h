//
// Created by uranus on 4/24/24.
//

#ifndef CMAKESFMLPROJECT_PADDLE_H
#define CMAKESFMLPROJECT_PADDLE_H

#include "SFML/Graphics.hpp"
#include "../../../Common/Base/Object.h"

class Paddle : public Object {
public:

    explicit Paddle(unsigned int player_number, int width, int height);

    void Update(float deltaTime) override;

private:

    sf::FloatRect CollisionBox;
    sf::RectangleShape rectShape;


    float m_paddle_width = 10;
    float m_paddle_height = 100;

    unsigned int m_player_number;
    float m_speed = 1000.0f;

    void MoveVerticallyClamped(float offsetY);
    void MoveHorizontallyClamped(float offsetX);
};


#endif //CMAKESFMLPROJECT_PADDLE_H
