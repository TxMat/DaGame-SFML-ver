//
// Created by uranus on 01/05/24.
//

#ifndef CMAKESFMLPROJECT_PHYSICSMANAGER_H
#define CMAKESFMLPROJECT_PHYSICSMANAGER_H


#include <vector>
#include "../Object.h"

class PhysicsManager {

public:

    explicit PhysicsManager(std::vector<Object *> *mGlobalObjectList);

    void Update();

protected:

    std::vector<Object*>* m_globalObjectList;

};


#endif //CMAKESFMLPROJECT_PHYSICSMANAGER_H
