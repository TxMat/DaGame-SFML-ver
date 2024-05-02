//
// Created by uranus on 01/05/24.
//

#include "UIManager.h"

void UIManager::Render(sf::RenderWindow &window) {
    for (auto &element: m_uiElements) {
        element->Render(window);
    }
    for (auto &element: m_fastUiElements) {
        element->Render(window);
    }
}

void UIManager::AddUIElement(UITextElement *element, bool shouldFastTick) {
    if (shouldFastTick) {
        m_fastUiElements.push_back(element);
    } else {
        m_uiElements.push_back(element);
    }
}

void UIManager::FixedTick(float deltaTime) {
    for (auto &element: m_uiElements) {
        element->Update(deltaTime);
    }
}

void UIManager::UnrestrictedTick(float deltaTime) {
    for (auto &element: m_fastUiElements) {
        element->Update(deltaTime);
    }
}
