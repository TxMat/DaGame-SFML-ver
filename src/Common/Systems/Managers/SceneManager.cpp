//
// Created by uranus on 01/05/24.
//

#include <thread>
#include "SceneManager.h"
#include "../../Globals.h"
#include "../../../Network/MainNetwork.h"

SceneManager::SceneManager(bool isServer) :
        m_isServer(isServer),
        m_ObjectManager(this),
        m_UIManager(this),
        m_NetworkManager(this),
        m_window(
                new sf::RenderWindow{{WIDTH, HEIGHT}, "Best App Ever"}) {
    m_fixedClock = sf::Clock();
    m_fastClock = sf::Clock();

//    m_window->setFramerateLimit(144);

    float objectsTickFps = 200; // keep it at a round number for better performance
    m_tickFramerate = sf::seconds(1.f / objectsTickFps);

    // todo manage this thread properly
    std::thread RM(&SceneManager::Tick, this);
    m_h = RM.native_handle();
    RM.detach();
}

void SceneManager::Tick() {
    while (isRunning) {

#if __linux__
        ListenEvent();
#endif
        float elapsedTime = m_fixedClock.restart().asSeconds();

        m_UIManager.FixedTick(elapsedTime);
        m_ObjectManager.FixedTick(elapsedTime);
        m_NetworkManager.FixedTick(elapsedTime);

        sleep(m_tickFramerate - m_fixedClock.getElapsedTime());
    }
}


void SceneManager::AddUIToScene(UITextElement *object, bool shouldFastTick) {
    m_UIManager.AddUIElement(object, shouldFastTick);
}

void SceneManager::AddObjectToScene(Object *object) {
    m_ObjectManager.AddObject(object);
}

void SceneManager::AddObjectToReplicate(Object *object, std::basic_string<char> name) {
    m_ReplicatedObjectList[name] = object;
}

Object* SceneManager::GetObjectToReplicate(std::string& name)
{
    return m_ReplicatedObjectList[name];
}

void SceneManager::UnrestrictedTick() {
    float elapsedTime = m_fastClock.restart().asSeconds();

#if _WIN32
    ListenEvent();
#endif

    m_UIManager.UnrestrictedTick(elapsedTime);
    m_ObjectManager.UnrestrictedTick(elapsedTime);

    m_window->clear();
    m_ObjectManager.Render(*m_window);
    m_UIManager.Render(*m_window);
    m_window->display();
}

void SceneManager::ListenEvent() {
    for (auto event = sf::Event{}; m_window->pollEvent(event);) {
        if (event.type == sf::Event::Closed) {
            isRunning = false;
//                pthread_cancel(m_h); // todo lag when closing
            m_window->close();
        }
    }
}

