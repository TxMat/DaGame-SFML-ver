//
// Created by uranus on 01/05/24.
//

#include "SceneManager.h"
#include "../../Globals.h"

SceneManager::SceneManager() :
        m_ObjectManager(),
        m_UIManager(),
        m_window(
                new sf::RenderWindow{{WIDTH, HEIGHT}, "Best App Ever"}) {
    m_clock = sf::Clock();
    // should work ?
    m_lastTime = m_clock.getElapsedTime();
//    m_window->setFramerateLimit(144);
}

void SceneManager::Tick() {

    for (auto event = sf::Event{}; m_window->pollEvent(event);) {
        if (event.type == sf::Event::Closed) {
            m_window->close();
        }
    }

    sf::Time currentTime = m_clock.getElapsedTime();
    auto elapsedTime = (currentTime - m_lastTime).asSeconds();
    m_lastTime = currentTime;

    m_UIManager.Tick(elapsedTime);
    m_ObjectManager.Tick(elapsedTime);

    m_window->clear();
    m_ObjectManager.Render(*m_window);
    m_UIManager.Render(*m_window);
    m_window->display();
}


void SceneManager::AddUIToScene(UITextElement *object) {
    m_UIManager.AddUIElement(object);
}

void SceneManager::AddObjectToScene(Object *object) {
    m_ObjectManager.AddObject(object);
}

