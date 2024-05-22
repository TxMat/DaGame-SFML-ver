//
// Created by uranus on 01/05/24.
//

#ifndef CMAKESFMLPROJECT_SCENEMANAGER_H
#define CMAKESFMLPROJECT_SCENEMANAGER_H


#include "UI/UIManager.h"
#include "Objects/ObjectManager.h"
#include "../../../Network/MainNetwork.h"
#include <thread>

class SceneManager {
public:

    explicit SceneManager(bool isServer);

    void Tick();

    void UnrestrictedTick();

    void AddObjectToScene(Object *object);

    void ListenEvent();

    void AddUIToScene(UITextElement *object, bool shouldFastTick);

    void AddObjectToReplicate(Object *object, std::string &name);

    Object* GetObjectToReplicate(std::string& name);

    bool isRunning = true;

    bool m_isServer = true;

private:

    std::vector<Object *> m_globalObjectList = std::vector<Object *>();

    std::map<std::string, Object *> m_ReplicatedObjectList = std::map<std::string , Object *>();

    ObjectManager m_ObjectManager;
    UIManager m_UIManager;

    sf::RenderWindow *m_window;

    sf::Time m_tickFramerate;

    sf::Clock m_fixedClock;
    sf::Clock m_fastClock;
    std::thread::native_handle_type m_h;
    MainNetwork m_net;
};


#endif //CMAKESFMLPROJECT_SCENEMANAGER_H
