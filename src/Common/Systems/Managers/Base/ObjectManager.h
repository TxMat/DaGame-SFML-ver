//
// Created by uranus on 01/05/24.
//

#ifndef CMAKESFMLPROJECT_OBJECTMANAGER_H
#define CMAKESFMLPROJECT_OBJECTMANAGER_H


#include <vector>
#include "BaseManager.h"
#include "../../../Object.h"

class ObjectManager : public BaseManager{

public:
    explicit ObjectManager(std::vector<Object *> &mGlobalObjectList);

protected:
    std::vector<Object*>& m_globalObjectList;

};


#endif //CMAKESFMLPROJECT_OBJECTMANAGER_H
