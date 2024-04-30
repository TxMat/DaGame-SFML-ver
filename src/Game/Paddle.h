//
// Created by uranus on 4/24/24.
//

#ifndef CMAKESFMLPROJECT_PADDLE_H
#define CMAKESFMLPROJECT_PADDLE_H
#include "SFML/Graphics.hpp"
#include "../Common/Object.h"

class Paddle: public Object {
public:

	Paddle(unsigned int player_number);
	void Update() override;

private:

	sf::FloatRect CollisionBox;
	sf::RectangleShape rectShape;

    static constexpr float m_paddle_width = 10;
    static constexpr float m_paddle_height = 100;

};


#endif //CMAKESFMLPROJECT_PADDLE_H
