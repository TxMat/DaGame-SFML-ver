//
// Created by uranus on 01/05/24.
//

#ifndef CMAKESFMLPROJECT_UIMANAGER_H
#define CMAKESFMLPROJECT_UIMANAGER_H


#include "../Base/BaseManager.h"
#include "SFML/Graphics/RenderWindow.hpp"
#include "../../../Base/UITextElement.h"

class UIManager : public BaseManager {
public:

    explicit UIManager(SceneManager *mSm) : BaseManager(mSm) {}

    void FixedTick(float deltaTime) override;

    void UnrestrictedTick(float deltaTime) override;

    void Render(sf::RenderWindow &window) override;

    void AddUIElement(UITextElement *element, bool shouldFastTick);

private:
    std::vector<UITextElement *> m_uiElements = std::vector<UITextElement *>();
    std::vector<UITextElement *> m_fastUiElements = std::vector<UITextElement *>();
};


#endif //CMAKESFMLPROJECT_UIMANAGER_H
