//
// Created by uranus on 01/05/24.
//

#include "PhysicsManager.h"

void PhysicsManager::Update() {
    for (auto object : *m_globalObjectList) {
        object->Update();
    }
}

PhysicsManager::PhysicsManager(std::vector<Object *> *mGlobalObjectList) : m_globalObjectList(mGlobalObjectList) {

}
