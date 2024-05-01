//
// Created by uranus on 01/05/24.
//

#include "RenderManager.h"
#include "../../Globals.h"

RenderManager::RenderManager(std::vector<Object *> &mGlobalObjectList) : ObjectManager(mGlobalObjectList), m_window(new sf::RenderWindow{ { WIDTH, HEIGHT }, "Best App Ever" }) {
    m_window->setFramerateLimit(144);
}

void RenderManager::Tick(sf::Time deltaTime) {

    for (auto event = sf::Event{}; m_window->pollEvent(event);)
    {
        if (event.type == sf::Event::Closed)
        {
            m_window->close();
        }
//        m_debug_text.setString(std::to_string(event.type));
    }

    m_window->clear();

    for (auto object : m_globalObjectList) {
        m_window->draw(*object->getMShape());
    }

    m_window->display();
}
