//
// Created by uranus on 01/05/24.
//

#include <thread>
#include "SceneManager.h"
#include "../../Globals.h"

SceneManager::SceneManager() :
        m_ObjectManager(),
        m_UIManager(),
        m_window(
                new sf::RenderWindow{{WIDTH, HEIGHT}, "Best App Ever"}) {
    m_fixedClock = sf::Clock();
    m_fastClock = sf::Clock();

//    m_window->setFramerateLimit(144);

    // todo manage this thread properly
    std::thread RM(&SceneManager::Tick, this);
    m_h = RM.native_handle();
    RM.detach();

}

void SceneManager::Tick() {
    while (isRunning) {
        for (auto event = sf::Event{}; m_window->pollEvent(event);) {
            if (event.type == sf::Event::Closed) {
                isRunning = false;
                pthread_cancel(m_h); // todo lag when closing
                m_window->close();
            }
        }

        float elapsedTime = m_fixedClock.restart().asSeconds();

        m_UIManager.FixedTick(elapsedTime);
        m_ObjectManager.FixedTick(elapsedTime);

        sleep(m_tickFramerate - m_fixedClock.getElapsedTime());
    }
}


void SceneManager::AddUIToScene(UITextElement *object, bool shouldFastTick) {
    m_UIManager.AddUIElement(object, shouldFastTick);
}

void SceneManager::AddObjectToScene(Object *object) {
    m_ObjectManager.AddObject(object);
}

void SceneManager::UnrestrictedTick() {
    float elapsedTime = m_fastClock.restart().asSeconds();

    m_UIManager.UnrestrictedTick(elapsedTime);
    m_ObjectManager.UnrestrictedTick(elapsedTime);

    m_window->clear();
    m_ObjectManager.Render(*m_window);
    m_UIManager.Render(*m_window);
    m_window->display();
}

