//
// Created by uranus on 4/24/24.
//

#ifndef CMAKESFMLPROJECT_PADDLE_H
#define CMAKESFMLPROJECT_PADDLE_H
#include "SFML/Graphics.hpp"
#include "../Common/Object.h"

class Paddle: Object {
public:
	Paddle();
	~Paddle();
	void Update() override;
private:
	sf::FloatRect CollisionBox;
	sf::RectangleShape rectShape;

};


#endif //CMAKESFMLPROJECT_PADDLE_H
