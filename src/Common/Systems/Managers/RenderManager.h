//
// Created by uranus on 01/05/24.
//

#ifndef CMAKESFMLPROJECT_RENDERMANAGER_H
#define CMAKESFMLPROJECT_RENDERMANAGER_H


#include <vector>
#include "../../Object.h"
#include "Base/ObjectManager.h"

class RenderManager : public ObjectManager {

public:

    explicit RenderManager(std::vector<Object *> &mGlobalObjectList);

    void Tick(sf::Time deltaTime) override;

    sf::RenderWindow *getWindow() const;

protected:
    sf::RenderWindow *m_window;
};


#endif //CMAKESFMLPROJECT_RENDERMANAGER_H
