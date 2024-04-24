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
//        object.getMShape()->move(5.f, 5.f);
        object.getMShape()->rotate(5.0f);
        m_window->draw(*object.getMShape());
    }

    m_currentTime = m_clock.getElapsedTime();
    double fps = 1.0f / (m_currentTime.asSeconds() - m_lastTime.asSeconds()); // the asSeconds returns a float
    m_fps.setString(std::string("Fps : " + std::to_string(floor(fps))));
    m_lastTime = m_currentTime;
    m_window->draw(m_fps);

    m_window->display();
}

void App::Init(const unsigned int width, const unsigned int height) {
    m_window = new sf::RenderWindow{ { width, height }, "Best App Ever" };
    m_window->setFramerateLimit(144);

    auto shape = Object(new sf::RectangleShape(sf::Vector2f(100.0f, 200.0f)));
    shape.getMShape()->setFillColor(sf::Color::Red);
    shape.getMShape()->setOrigin(50, 100);
    shape.getMShape()->setPosition(width/2, height/2);

    if (!m_font.loadFromFile("Montserrat-SemiBold.ttf"))
    {

    }

    m_fps = sf::Text();
    m_fps.setFont(m_font);
    m_fps.setOrigin(0, 0);
    m_fps.setFillColor(sf::Color::Green);
    m_fps.setCharacterSize(20);
    m_window->draw(m_fps);


    m_objectList.push_back(shape);
}

App::App() {
    m_clock = sf::Clock();
}

void App::Loop() {
    while (m_window->isOpen())
    {
        this->Update();
        this->Render();
    }
}

void App::Render() {

}

