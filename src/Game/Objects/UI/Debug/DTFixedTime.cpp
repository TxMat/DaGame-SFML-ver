//
// Created by uranus on 15/05/24.
//

#include <cmath>
#include "DTFixedTime.h"
#include "../../../../Common/Globals.h"

DTFixedTime::DTFixedTime() : UITextElement() {
    m_text.setFillColor(sf::Color::Cyan);
    m_text.setPosition(WIDTH - 350, 0);
}

void DTFixedTime::Update(float deltaTime) {
    double fps = 1.0f / deltaTime; // the asSeconds returns a float
    m_text.setString(std::string("Fixed Update Fps : " + std::to_string(floor(fps))));
}
