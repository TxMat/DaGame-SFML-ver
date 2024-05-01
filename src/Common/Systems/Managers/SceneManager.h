//
// Created by uranus on 01/05/24.
//

#ifndef CMAKESFMLPROJECT_SCENEMANAGER_H
#define CMAKESFMLPROJECT_SCENEMANAGER_H


#include "RenderManager.h"
#include "PhysicsManager.h"

class SceneManager {
public:

    void Tick();

    void AddToScene(Object *object);

    void Destroy(Object *object);

    SceneManager();

    bool isRunning = true;

private:

    std::vector<Object *> m_globalObjectList = std::vector<Object *>();

    PhysicsManager m_physicsManager;
    RenderManager m_renderManager;

    sf::Window *m_window;

    sf::Clock m_clock;
    sf::Time m_lastTime;
};


#endif //CMAKESFMLPROJECT_SCENEMANAGER_H
