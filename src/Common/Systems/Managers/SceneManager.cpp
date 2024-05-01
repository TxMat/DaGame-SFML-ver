//
// Created by uranus on 01/05/24.
//

#include "SceneManager.h"

SceneManager::SceneManager() : m_physicsManager(m_globalObjectList), m_renderManager(m_globalObjectList) {
    m_clock = sf::Clock();
    // should work ?
    m_lastTime = m_clock.getElapsedTime();
}

void SceneManager::Tick() {
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
    m_globalObjectList.erase(std::remove(m_globalObjectList.begin(), m_globalObjectList.end(), object),
                             m_globalObjectList.end());
}

