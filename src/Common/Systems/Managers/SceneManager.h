//
// Created by uranus on 01/05/24.
//

#ifndef CMAKESFMLPROJECT_SCENEMANAGER_H
#define CMAKESFMLPROJECT_SCENEMANAGER_H


#include "UI/UIManager.h"
#include "Objects/ObjectManager.h"
#include <thread>

class SceneManager {
public:

    SceneManager();

    void Tick();

    void UnrestrictedTick();

    void AddObjectToScene(Object *object);

    void AddUIToScene(UITextElement *object, bool shouldFastTick);

    bool isRunning = true;

private:

    std::vector<Object *> m_globalObjectList = std::vector<Object *>();

    ObjectManager m_ObjectManager;
    UIManager m_UIManager;

    sf::RenderWindow *m_window;

    sf::Time m_tickFramerate = sf::seconds(1.f / 144);

    sf::Clock m_fixedClock;
    sf::Clock m_fastClock;
    std::thread::native_handle_type m_h;
};


#endif //CMAKESFMLPROJECT_SCENEMANAGER_H
