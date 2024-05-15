//
// Created by uranus on 4/24/24.
//

#ifndef CMAKESFMLPROJECT_BALL_H
#define CMAKESFMLPROJECT_BALL_H

#include "SFML/Graphics.hpp"
#include "../../../Common/Base/Object.h"


class Ball : public Object {

public:
    Ball(float speed, float radius);

    void Update(float deltaTime) override;

    bool CheckCollision(Object *other) override;

    void HandleCollision(Object *other) override;

    

private:
    float m_speed;

};


#endif //CMAKESFMLPROJECT_BALL_H
