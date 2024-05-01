//
// Created by uranus on 01/05/24.
//

#ifndef CMAKESFMLPROJECT_PHYSICSMANAGER_H
#define CMAKESFMLPROJECT_PHYSICSMANAGER_H


#include <vector>
#include "../../Object.h"
#include "Base/ObjectManager.h"

class PhysicsManager : public ObjectManager {

public:

    explicit PhysicsManager(std::vector<Object *> &mGlobalObjectList);

    void Tick(sf::Time deltaTime) override;

};


#endif //CMAKESFMLPROJECT_PHYSICSMANAGER_H
