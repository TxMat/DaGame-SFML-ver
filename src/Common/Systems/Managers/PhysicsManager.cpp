//
// Created by uranus on 01/05/24.
//

#include "PhysicsManager.h"

PhysicsManager::PhysicsManager(std::vector<Object *> &mGlobalObjectList) : ObjectManager(mGlobalObjectList) {

}

void PhysicsManager::Tick(sf::Time deltaTime) {
    for (auto object: m_globalObjectList) {
        object->Update(deltaTime);
    }
}
