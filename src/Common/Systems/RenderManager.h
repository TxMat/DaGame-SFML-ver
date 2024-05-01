//
// Created by uranus on 01/05/24.
//

#ifndef CMAKESFMLPROJECT_RENDERMANAGER_H
#define CMAKESFMLPROJECT_RENDERMANAGER_H


#include <vector>
#include "../Object.h"

class RenderManager {

public:

    explicit RenderManager(std::vector<Object *> *mGlobalObjectList);

    void Update();

protected:

    std::vector<Object*>* m_globalObjectList;

};


#endif //CMAKESFMLPROJECT_RENDERMANAGER_H
