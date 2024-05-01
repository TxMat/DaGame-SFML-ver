//
// Created by uranus on 01/05/24.
//

#ifndef CMAKESFMLPROJECT_UIMANAGER_H
#define CMAKESFMLPROJECT_UIMANAGER_H


#include "Base/BaseManager.h"
#include "SFML/Graphics/RenderWindow.hpp"
#include "../../Base/UITextElement.h"

class UIManager : public BaseManager{
public:
    void Tick(sf::Time deltaTime) override {
        for (auto& element : m_uiElements) {
            element->Update(deltaTime);
        }
    }

    void Render(sf::RenderWindow& window) {
        for (auto& element : m_uiElements) {
            element->Render(window);
        }
    }

    void AddUIElement(UITextElement* element) {
        m_uiElements.push_back(element);
    }

private:
    std::vector<UITextElement*> m_uiElements;
};


#endif //CMAKESFMLPROJECT_UIMANAGER_H
