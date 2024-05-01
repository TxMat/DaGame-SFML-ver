//
// Created by uranus on 01/05/24.
//

#include "ObjectManager.h"

void ObjectManager::Tick(float deltaTime) {
    for (auto object: m_globalObjectList) {
        object->Update(deltaTime);
    }
}

void ObjectManager::Render(sf::RenderWindow &window) {
    for (auto object: m_globalObjectList) {
        window.draw(*object->getMShape());
    }
}

void ObjectManager::AddObject(Object *object) {
    m_globalObjectList.push_back(object);
}