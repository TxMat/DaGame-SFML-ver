//
// Created by uranus on 4/24/24.
//

#include "Paddle.h"
#include "../../../Common/Globals.h"

Paddle::Paddle(unsigned int player_number, int width, int height): NetworkObject(
        new sf::RectangleShape(sf::Vector2f(width, height)),
        "Paddle_P" + std::to_string(player_number)), m_player_number(player_number) {
    m_shape->setFillColor(sf::Color::Red);
    m_shape->setOrigin(m_paddle_width / 2, m_paddle_height / 2);
    b_shouldGenerateHits = true;
    switch (player_number) {
        case 1:
            m_shape->setPosition(100, HEIGHT / 2);
            m_forward_vector = sf::Vector2f(1.0f, 0.0f);
            break;
        case 2:
            m_shape->setPosition(WIDTH - 100, HEIGHT / 2);
            m_forward_vector = sf::Vector2f(-1.0f, 0.0f);
            break;
        case 3:
            m_shape->setPosition(WIDTH / 2, HEIGHT);
            m_forward_vector = sf::Vector2f(0.0f, 1.0f);
            break;
        case 4:
            m_shape->setPosition(WIDTH / 2, 100);
            m_forward_vector = sf::Vector2f(0.0f, -1.0f);
            break;
        default:
            m_shape->setPosition(WIDTH / 2, HEIGHT / 2);
            break;
    }
}

void Paddle::Update(float deltaTime) {
    switch (m_player_number) {
        case 1:
            // todo refactor this
            if (sf::Keyboard::isKeyPressed(sf::Keyboard::Z)) {
                MoveVerticallyClamped(-m_speed * deltaTime);
            } else if (sf::Keyboard::isKeyPressed(sf::Keyboard::S)) {
                MoveVerticallyClamped(m_speed * deltaTime);
            }
            break;
        case 2:
        default:
            if (sf::Keyboard::isKeyPressed(sf::Keyboard::Up)) {
                MoveVerticallyClamped(-m_speed * deltaTime);
            } else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Down)) {
                MoveVerticallyClamped(m_speed * deltaTime);
            }
            break;
        case 3:
            if (sf::Keyboard::isKeyPressed(sf::Keyboard::Left)) {
                MoveHorizontallyClamped(-m_speed * deltaTime);
            }
            else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Right)) {
                MoveHorizontallyClamped(m_speed * deltaTime);
            }
            break;
        case 4:
            if (sf::Keyboard::isKeyPressed(sf::Keyboard::Q)) {
                MoveHorizontallyClamped(-m_speed * deltaTime);
            }
            else if (sf::Keyboard::isKeyPressed(sf::Keyboard::D)) {
                MoveHorizontallyClamped(m_speed * deltaTime);
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

void Paddle::MoveHorizontallyClamped(float offsetX)
{
    auto x = m_shape->getPosition().x + offsetX;
    if (x < WIDTH && x > 0) {
        m_shape->move(offsetX,0.0);
    }
}

NetworkPacket Paddle::GetNetworkPacket() {
    std::vector<uint8_t> p = {};
    return NetworkPacket(PosSync, 4, p);
}

void Paddle::DeserializePayload(std::vector<uint8_t> &payload) {

}
