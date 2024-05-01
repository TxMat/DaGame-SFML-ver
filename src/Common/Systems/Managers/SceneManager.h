//
// Created by uranus on 01/05/24.
//

#ifndef CMAKESFMLPROJECT_SCENEMANAGER_H
#define CMAKESFMLPROJECT_SCENEMANAGER_H


#include "UI/UIManager.h"
#include "Objects/ObjectManager.h"

class SceneManager {
public:

    void Tick();

    void AddObjectToScene(Object *object);

    void AddUIToScene(UITextElement *object);

    void Destroy(Object *object);

    SceneManager();

    bool isRunning = true;

private:

    std::vector<Object *> m_globalObjectList = std::vector<Object *>();

    ObjectManager m_ObjectManager;
    UIManager m_UIManager;

    sf::RenderWindow *m_window;

    sf::Clock m_clock;
    sf::Time m_lastTime;
};


#endif //CMAKESFMLPROJECT_SCENEMANAGER_H
