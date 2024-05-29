//
// Created by uranus on 4/24/24.
//

#include <cmath>
#include <random>
#include <iostream>
#include <cstring>
#include "Ball.h"
#include "../../../Common/Globals.h"

Ball::Ball(float speed, float radius) : NetworkObject(new sf::CircleShape(radius), "Ball") {
    m_shape->setOrigin(radius, radius);
    m_speed = speed;
    b_shouldGenerateHits = true;
    b_shouldHandleCollision = true;

    std::random_device rd;

    std::mt19937 gen(rd()); // Mersenne Twister 19937 generator

    // Random distribution for x and y coordinates
    std::uniform_real_distribution<float> dis(-1.0f, 1.0f);

    // Generate random x and y coordinates
    float x = dis(gen);
    float y = dis(gen);

    if (x < -.5f) {
        m_shape->setFillColor(sf::Color::Cyan);
    } else if (x < 0) {
        m_shape->setFillColor(sf::Color::Green);
    } else if (x < .5f) {
        m_shape->setFillColor(sf::Color::Magenta);
    }
    else {
        m_shape->setFillColor(sf::Color::Yellow);
    }

    // Normalize the direction vector
    float magnitude = std::sqrt(x * x + y * y);
    m_normalized_speed_vector = sf::Vector2f(x / magnitude, y / magnitude);
}

void Ball::Update(float deltaTime) {
    Object::Update(deltaTime);
    auto pos = m_shape->getPosition();
    if (pos.x > WIDTH || pos.x < 0) {
        m_normalized_speed_vector.x = m_normalized_speed_vector.x * -1;
    } else if (pos.y > HEIGHT || pos.y < 0) {
        m_normalized_speed_vector.y = m_normalized_speed_vector.y * -1;
    }

    //	float x = collisionNormal.x != 0.0 ? m_normalized_speed_vector.x * collisionNormal.x : m_normalized_speed_vector.x;
//	float y = collisionNormal.y != 0.0 ? m_normalized_speed_vector.y * collisionNormal.y : m_normalized_speed_vector.y;
//	m_normalized_speed_vector = sf::Vector2f(x, y);

    m_shape->move(((m_speed * deltaTime) * m_normalized_speed_vector));
}

bool Ball::CheckCollision(Object *other) {
    return m_shape->getGlobalBounds().intersects(other->getMShape()->getGlobalBounds());
}

void Ball::HandleCollision(Object *other) {

    sf::Vector2f otherForwardVector = other->m_forward_vector;
    sf::Vector2f otherPosition = other->getMShape()->getPosition();
    sf::Vector2f ownPosition = m_shape->getPosition();

    float size = 50.0;
    float offset;

    if (otherForwardVector.x != 0)
    {
        m_normalized_speed_vector.x *= -1;
        offset = std::clamp(std::abs(otherPosition.y - ownPosition.y) / size, 0.1f, 1.0f);
        m_normalized_speed_vector.y = (m_normalized_speed_vector.y >= 0 ? offset : -offset);
    }
    else if (otherForwardVector.y != 0)
    {
        m_normalized_speed_vector.y *= -1;
        offset = std::clamp(std::abs(otherPosition.x - ownPosition.x) / size, 0.1f, 1.0f);
        m_normalized_speed_vector.x = (m_normalized_speed_vector.x >= 0 ? offset : -offset);
    }
    
    float magnitude = std::sqrt(m_normalized_speed_vector.x * m_normalized_speed_vector.x + m_normalized_speed_vector.y * m_normalized_speed_vector.y);
    m_normalized_speed_vector.x /= magnitude;
    m_normalized_speed_vector.y /= magnitude;
}

NetworkPacket Ball::GetNetworkPacket() {
    auto pos = m_shape->getPosition();

    std::vector<uint8_t> p;

    // Serialize pos.x
    const auto* px = reinterpret_cast<const uint8_t*>(&pos.x);
    p.insert(p.end(), px, px + sizeof(pos.x));

    // Serialize pos.y
    const auto* py = reinterpret_cast<const uint8_t*>(&pos.y);
    p.insert(p.end(), py, py + sizeof(pos.y));

    return NetworkPacket{PosSync, p};
}

void Ball::DeserializePayload(std::vector<uint8_t>& payload) {
    float x, y;
    size_t floatSize = sizeof(float);
    std::memcpy(&x, &payload[0], floatSize);
    std::memcpy(&y, &payload[floatSize], floatSize);
    sf::Vector2f newPos = sf::Vector2f(x, y);
}
