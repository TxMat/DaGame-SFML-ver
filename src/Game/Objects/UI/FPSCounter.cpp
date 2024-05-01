//
// Created by uranus on 01/05/24.
//

#include <cmath>
#include "FPSCounter.h"

FPSCounter::FPSCounter() {

    m_font = sf::Font();
    if (!m_font.loadFromFile("Montserrat-SemiBold.ttf")) {
        printf("failed");
    }

    m_text.setFont(m_font);
    m_text.setFillColor(sf::Color::Green);
    m_text.setCharacterSize(20);
}

void FPSCounter::Update(sf::Time deltaTime) {
    double fps = 1.0f / deltaTime.asSeconds(); // the asSeconds returns a float
    m_text.setString(std::string("Fps : " + std::to_string(floor(fps))));
}
