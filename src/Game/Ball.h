//
// Created by uranus on 4/24/24.
//

#ifndef CMAKESFMLPROJECT_BALL_H
#define CMAKESFMLPROJECT_BALL_H

#include "SFML/Graphics.hpp"
#include "../Common/Object.h"


class Ball: public Object {

public:
	Ball(float speed, float radius);
	void Update() override;

private:
	float m_speed;
	sf::Vector2f m_direction;

};


#endif //CMAKESFMLPROJECT_BALL_H
