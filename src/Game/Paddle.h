//
// Created by uranus on 4/24/24.
//

#ifndef CMAKESFMLPROJECT_PADDLE_H
#define CMAKESFMLPROJECT_PADDLE_H


#include "../Common/Object.h"

class Paddle : public Object{
public:
	Paddle();
	~Paddle();
	void Update() override;

};


#endif //CMAKESFMLPROJECT_PADDLE_H
