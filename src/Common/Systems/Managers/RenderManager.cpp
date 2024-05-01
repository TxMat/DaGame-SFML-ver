//
// Created by uranus on 01/05/24.
//

#include "RenderManager.h"
#include "../../Globals.h"

RenderManager::RenderManager(std::vector<Object *> &mGlobalObjectList) : ObjectManager(mGlobalObjectList), m_window(new sf::RenderWindow{ { WIDTH, HEIGHT }, "Best App Ever" }) {
    m_window->setFramerateLimit(144);
}

void RenderManager::Tick(sf::Time deltaTime) {
    m_window->clear();

    for (auto object : m_globalObjectList) {
        m_window->draw(*object->getMShape());
    }

    m_window->display();
}

sf::RenderWindow *RenderManager::getWindow() const {
    return m_window;
}
