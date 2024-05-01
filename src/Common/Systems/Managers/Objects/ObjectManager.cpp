//
// Created by uranus on 01/05/24.
//

#include "ObjectManager.h"

ObjectManager::ObjectManager(std::vector<Object *> &mGlobalObjectList) : m_globalObjectList(mGlobalObjectList) {

}

void ObjectManager::Tick(sf::Time deltaTime) {
    for (auto object: m_globalObjectList) {
        object->Update(deltaTime);
    }
}

void ObjectManager::Render(sf::RenderWindow &window) {
    for (auto object: m_globalObjectList) {
        window.draw(*object->getMShape());
    }
}
