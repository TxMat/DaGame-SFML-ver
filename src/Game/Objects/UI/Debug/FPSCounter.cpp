//
// Created by uranus on 01/05/24.
//

#include <cmath>
#include "FPSCounter.h"

FPSCounter::FPSCounter() : UITextElement() {
    m_text.setFillColor(sf::Color::Green);
}

void FPSCounter::Update(float deltaTime) {
    double fps = 1.0f / deltaTime; // the asSeconds returns a float
    m_text.setString(std::string("Fps : " + std::to_string(floor(fps))));
}
