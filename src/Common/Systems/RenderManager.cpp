//
// Created by uranus on 01/05/24.
//

#include "RenderManager.h"

void RenderManager::Update() {
    for (const auto& object : *m_globalObjectList) {
//        m_window->draw(*object->getMShape());
    }
}

RenderManager::RenderManager(std::vector<Object *> *mGlobalObjectList) : m_globalObjectList(mGlobalObjectList) {

}
