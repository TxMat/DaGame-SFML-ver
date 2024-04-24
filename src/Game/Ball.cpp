//
// Created by uranus on 4/24/24.
//

#include "Ball.h"

void Ball::Update()
{
	//shape.move(m_speed * m_direction);
}

void Ball::Collide(sf::Vector2f collisionNormal)
{
	float x = collisionNormal.x != 0.0 ? m_direction.x * collisionNormal.x : m_direction.x;
	float y = collisionNormal.y != 0.0 ? m_direction.y * collisionNormal.y : m_direction.y;
	m_direction = sf::Vector2f(x, y);
}
