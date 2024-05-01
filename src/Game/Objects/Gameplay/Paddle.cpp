//
// Created by uranus on 4/24/24.
//

#include "Paddle.h"
#include "../../../Common/Globals.h"

Paddle::Paddle(unsigned int player_number) : Object(
        new sf::RectangleShape(sf::Vector2f(m_paddle_width, m_paddle_height)),
        "Paddle_P" + std::to_string(player_number)), m_player_number(player_number) {
    m_shape->setFillColor(sf::Color::Red);
    m_shape->setOrigin(m_paddle_width / 2, m_paddle_height / 2);
    b_shouldSimulatePhysics = true;
    switch (player_number) {
        case 1:
            m_shape->setPosition(100, HEIGHT / 2);
            break;
        case 2:
            m_shape->setPosition(WIDTH - 100, HEIGHT / 2);
            break;
        default:
            m_shape->setPosition(WIDTH / 2, HEIGHT / 2);
            break;
    }
}

void Paddle::Update(sf::Time deltaTime) {
    switch (m_player_number) {
        case 1:
            if (sf::Keyboard::isKeyPressed(sf::Keyboard::Z)) {
                MoveVerticallyClamped(-5.f);
            } else if (sf::Keyboard::isKeyPressed(sf::Keyboard::S)) {
                MoveVerticallyClamped(5.f);
            }
            break;
        case 2:
        default:
            if (sf::Keyboard::isKeyPressed(sf::Keyboard::Up)) {
                MoveVerticallyClamped(-5.f);
            } else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Down)) {
                MoveVerticallyClamped(5.f);
            }
            break;
    }
}

void Paddle::MoveVerticallyClamped(float offsetY) {
    auto y = m_shape->getPosition().y + offsetY;
    if (y < HEIGHT && y > 0) {
        m_shape->move(0.0, offsetY);
    }
}
