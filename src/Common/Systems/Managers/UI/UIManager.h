//
// Created by uranus on 01/05/24.
//

#ifndef CMAKESFMLPROJECT_UIMANAGER_H
#define CMAKESFMLPROJECT_UIMANAGER_H


#include "../Base/BaseManager.h"
#include "SFML/Graphics/RenderWindow.hpp"
#include "../../../Base/UITextElement.h"

class UIManager : public BaseManager{
public:
    void Tick(float deltaTime) override;

    void Render(sf::RenderWindow& window) override;

    void AddUIElement(UITextElement* element);

private:
    std::vector<UITextElement*> m_uiElements;
};


#endif //CMAKESFMLPROJECT_UIMANAGER_H
