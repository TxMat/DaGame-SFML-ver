//
// Created by uranus on 01/05/24.
//

#include "UITextElement.h"

UITextElement::UITextElement() {
    m_font = sf::Font();
    if (!m_font.loadFromFile("Montserrat-SemiBold.ttf")) {
        printf("failed");
    }

    m_text.setFont(m_font);
    m_text.setFillColor(sf::Color::White);
    m_text.setCharacterSize(20);
}
