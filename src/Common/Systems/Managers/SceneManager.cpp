//
// Created by uranus on 01/05/24.
//

#include "SceneManager.h"

SceneManager::SceneManager() :
m_physicsManager(m_globalObjectList),
m_renderManager(m_globalObjectList),
m_UIManager()
{
    m_clock = sf::Clock();
    // should work ?
    m_lastTime = m_clock.getElapsedTime();
    m_window = m_renderManager.getWindow();
}

void SceneManager::Tick() {

    sf::Time currentTime = m_clock.getElapsedTime();
    auto elapsedTime = currentTime - m_lastTime;
    m_lastTime = currentTime;

    m_physicsManager.Tick(elapsedTime);
    m_UIManager.Tick(elapsedTime);

    m_window->clear();
    m_renderManager.Tick(elapsedTime);
    m_UIManager.Render(*m_window);
    m_window->display();
}

void SceneManager::AddObjectToScene(Object *object) {
    m_globalObjectList.push_back(object);
}

void SceneManager::Destroy(Object *object) {
    delete object;
    m_globalObjectList.erase(std::remove(m_globalObjectList.begin(), m_globalObjectList.end(), object),
                             m_globalObjectList.end());
}

void SceneManager::AddUIToScene(UITextElement *object) {
    m_UIManager.AddUIElement(object);
}

