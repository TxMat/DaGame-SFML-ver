//
// Created by uranus on 01/05/24.
//

#ifndef CMAKESFMLPROJECT_BASEMANAGER_H
#define CMAKESFMLPROJECT_BASEMANAGER_H

#include "SFML/System/Time.hpp"

class BaseManager {
public:
    virtual void Tick(sf::Time deltaTime) = 0;
};


#endif //CMAKESFMLPROJECT_BASEMANAGER_H
