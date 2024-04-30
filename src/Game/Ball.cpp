//
// Created by uranus on 4/24/24.
//

#include <cmath>
#include <random>
#include "Ball.h"
#include "../Common/Globals.h"

Ball::Ball(float speed, float radius) : Object(new sf::CircleShape(radius)) {
    m_shape->setFillColor(sf::Color::White);
    m_shape->setOrigin(radius, radius);
	m_speed = speed;

    std::random_device rd;
    std::mt19937 gen(rd()); // Mersenne Twister 19937 generator

    // Random distribution for x and y coordinates
    std::uniform_real_distribution<float> dis(-1.0f, 1.0f);

    // Generate random x and y coordinates
    float x = dis(gen);
    float y = dis(gen);

    // Normalize the direction vector
    float magnitude = std::sqrt(x * x + y * y);
    m_direction = sf::Vector2f(x / magnitude, y / magnitude);
}

void Ball::Update()
{
    Object::Update();
    printf("x:%f, y:%f\n", m_shape->getPosition().x, m_shape->getPosition().y);
    if (m_shape->getPosition().x > WIDTH || m_shape->getPosition().x < 0) {
        m_direction.x = m_direction.x * -1;
    } else if (m_shape->getPosition().y > HEIGHT || m_shape->getPosition().y < 0) {
        m_direction.y = m_direction.y * -1;
    }
	m_shape->move(m_speed * m_direction);
}

void Ball::Collide(sf::Vector2f collisionNormal)
{
	float x = collisionNormal.x != 0.0 ? m_direction.x * collisionNormal.x : m_direction.x;
	float y = collisionNormal.y != 0.0 ? m_direction.y * collisionNormal.y : m_direction.y;
	m_direction = sf::Vector2f(x, y);
}
