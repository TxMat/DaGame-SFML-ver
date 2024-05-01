//
// Created by uranus on 01/05/24.
//

#include <cmath>
#include "DT.h"


DT::DT() : UITextElement() {
    m_text.setFillColor(sf::Color::Red);
    m_text.setPosition(250, 0);
}

void DT::Update(float deltaTime) {
    m_text.setString(std::string("Delta Time : " + std::to_string((deltaTime*1000)) + "ms"));
}