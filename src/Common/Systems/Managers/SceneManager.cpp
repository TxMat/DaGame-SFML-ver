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
    m_clock = sf::Clock();

//    m_window->setFramerateLimit(144);

//    MAX FPS MODE --> uncomment the following and comment m_ObjectManager.Tick(elapsedTime);
//    Note : No sync as of now might crash 1/2 times

//    std::thread objectManagerThread(&ObjectManager::AutoTick, &m_ObjectManager);
//    objectManagerThread.detach();
}

void SceneManager::Tick() {

    for (auto event = sf::Event{}; m_window->pollEvent(event);) {
        if (event.type == sf::Event::Closed) {
            isRunning = false;
            m_window->close();
        }
    }

    float elapsedTime = m_clock.restart().asSeconds();

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

