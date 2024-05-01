//
// Created by uranus on 01/05/24.
//

#include "UIManager.h"

void UIManager::Render(sf::RenderWindow &window) {
    for (auto& element : m_uiElements) {
        element->Render(window);
    }
}

void UIManager::AddUIElement(UITextElement *element) {
    m_uiElements.push_back(element);
}

void UIManager::Tick(float deltaTime) {
    for (auto& element : m_uiElements) {
        element->Update(deltaTime);
    }
}
