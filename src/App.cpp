//
// Created by uranus on 4/24/24.
//

#include <cmath>
#include <iostream>
#include "App.h"

void App::Update() {
    for (auto event = sf::Event{}; m_window->pollEvent(event);)
    {
        if (event.type == sf::Event::Closed)
        {
            m_window->close();
        }
    }

    m_window->clear();
    for (auto object : m_objectList) {
        object.getMShape()->move(5.f, 5.f);
        object.getMShape()->rotate(5.0f);
        m_window->draw(*object.getMShape());
    }
    m_window->display();

    m_currentTime = m_clock.getElapsedTime();
    double fps = 1.0f / (m_currentTime.asSeconds() - m_lastTime.asSeconds()); // the asSeconds returns a float
    std::cout << "fps =" << floor(fps) << std::endl; // flooring it will make the frame rate a rounded number
    m_lastTime = m_currentTime;
}

void App::Init(const unsigned int width, const unsigned int height) {
    m_window = new sf::RenderWindow{ { width, height }, "Best App Ever" };
    m_window->setFramerateLimit(144);

    auto shape = Object(sf::Vector2f(100.0f, 200.0f));
    shape.getMShape()->setFillColor(sf::Color::Red);
    shape.getMShape()->setOrigin(50, 100);

    m_objectList.push_back(shape);

    while (m_window->isOpen())
    {
        this->Update();
    }
}

App::App() {
    m_clock = sf::Clock();
}

