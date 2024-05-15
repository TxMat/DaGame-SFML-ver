//
// Created by uranus on 01/05/24.
//

#include "ObjectManager.h"

void ObjectManager::FixedTick(float deltaTime) {
    ObjectManager::TickInternal(deltaTime, m_globalObjectList);
}

void ObjectManager::Render(sf::RenderWindow &window) {
    for (auto object: m_globalObjectList) {
        window.draw(*object->getMShape());
    }
}

void ObjectManager::AddObject(Object *object) {
    m_globalObjectList.push_back(object);
}

void ObjectManager::UnrestrictedTick(float deltaTime) {
    ObjectManager::TickInternal(deltaTime, m_fastGlobalObjectList);
}

void ObjectManager::TickInternal(float deltaTime, const std::vector<Object*>& objectList) {
    for (auto object: objectList) {
        if (object->b_shouldHandleCollision) {
            for (auto p_object: objectList) {
                if (p_object == object) {
                    continue;
                }
                // todo refactor lmao
                if (p_object->b_shouldGenerateHits) {
                    if (object->CheckCollision(p_object) && std::find(object->m_HitList.begin(), object->m_HitList.end(), p_object) == object->m_HitList.end()) {
                        object->m_HitList.push_back(p_object);
                        object->HandleCollision(p_object);
                    }
                    if (std::find(object->m_HitList.begin(), object->m_HitList.end(), p_object) != object->m_HitList.end()) {
                        if (!object->CheckCollision(p_object)) {
                            object->m_HitList.erase(std::remove(object->m_HitList.begin(), object->m_HitList.end(), p_object), object->m_HitList.end());
                        }
                    }
                }
            }
        }
        object->Update(deltaTime);
    }
}
