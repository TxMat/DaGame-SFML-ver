//
// Created by uranus on 01/05/24.
//

#include "SceneManager.h"

SceneManager::SceneManager(): m_physicsManager(m_globalObjectList), m_renderManager(m_globalObjectList) {
    m_clock = sf::Clock();
    // should work ?
    m_lastTime = m_clock.getElapsedTime();
    m_window = m_renderManager.getWindow();
}

void SceneManager::Tick() {

    // todo somehow pass events to Tick
    for (auto event = sf::Event{}; m_window->pollEvent(event);)
    {
        if (event.type == sf::Event::Closed)
        {
            m_window->close();
        }
//        m_debug_text.setString(std::to_string(event.type));
    }

    sf::Time currentTime = m_clock.getElapsedTime();
    auto elapsedTime = currentTime - m_lastTime;
    m_physicsManager.Tick(elapsedTime);
    m_renderManager.Tick(elapsedTime);
}

void SceneManager::AddToScene(Object *object) {
    m_globalObjectList.push_back(object);
}

void SceneManager::Destroy(Object *object) {
    delete object;
    m_globalObjectList.erase(std::remove(m_globalObjectList.begin(), m_globalObjectList.end(), object), m_globalObjectList.end());
}

