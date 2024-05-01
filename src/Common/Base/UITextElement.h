//
// Created by uranus on 01/05/24.
//

#ifndef CMAKESFMLPROJECT_UITEXTELEMENT_H
#define CMAKESFMLPROJECT_UITEXTELEMENT_H


#include <utility>

#include "SFML/Graphics/Text.hpp"
#include "SFML/System/Time.hpp"
#include "SFML/Graphics/RenderWindow.hpp"

class UITextElement {
public:

    UITextElement() = default;

    virtual void Update(sf::Time deltaTime) = 0;

    virtual void Render(sf::RenderWindow &window) {
        window.draw(m_text);
    }

protected:
    sf::Text m_text;
};


#endif //CMAKESFMLPROJECT_UITEXTELEMENT_H
