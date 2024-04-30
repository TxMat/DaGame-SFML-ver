//
// Created by uranus on 4/24/24.
//

#include "Paddle.h"
#include "../Common/Globals.h"

// how
Paddle::Paddle(unsigned int player_number) : Object(new sf::RectangleShape(sf::Vector2f(m_paddle_width, m_paddle_height))){
    m_shape->setFillColor(sf::Color::Red);
    m_shape->setOrigin(m_paddle_width/2, m_paddle_height/2);
    switch (player_number) {
        case 1:
            m_shape->setPosition(100, HEIGHT/2);
            break;
        case 2:
            m_shape->setPosition(WIDTH - 100, HEIGHT/2);
            break;
        default:
            m_shape->setPosition(WIDTH / 2, HEIGHT/2);
            break;
    }
}

void Paddle::Update() {
//    m_shape->rotate(5.0f);
}
