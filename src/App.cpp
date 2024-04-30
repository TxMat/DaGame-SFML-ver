//
// Created by uranus on 4/24/24.
//

#include <cmath>
#include <iostream>
#include "App.h"
#include "Game/Ball.h"
#include "Game/Paddle.h"

void App::Tick() {

    for (auto object : m_objectList) {
        object->Update();
    }

    m_currentTime = m_clock.getElapsedTime();
    double fps = 1.0f / (m_currentTime.asSeconds() - m_lastTime.asSeconds()); // the asSeconds returns a float
    m_fps.setString(std::string("Fps : " + std::to_string(floor(fps))));
    m_lastTime = m_currentTime;
}

void App::Render() {
    m_window->clear();

    for (const auto& object : m_objectList) {
        m_window->draw(*object->getMShape());
    }

    m_window->draw(m_fps);
    m_window->draw(m_debug_text);

    m_window->display();

}

void App::Init(const unsigned int width, const unsigned int height) {
    m_window = new sf::RenderWindow{ { width, height }, "Best App Ever" };
    m_window->setFramerateLimit(144);

    Object* playerOnePaddle = new Paddle(1);
    m_objectList.push_back(playerOnePaddle);

    Object* playerTwoPaddle = new Paddle(2);
    m_objectList.push_back(playerTwoPaddle);

    Object *ball = new Ball(1, 10);
    ball->getMShape()->setPosition(width / 2, height / 2);
    m_objectList.push_back(ball);

    if (!m_font.loadFromFile("Montserrat-SemiBold.ttf"))
    {
        printf("failed");
    }

    printf("OK");

    m_fps = sf::Text();
    m_fps.setFont(m_font);
    m_fps.setFillColor(sf::Color::Green);
    m_fps.setCharacterSize(20);
    m_window->draw(m_fps);

    m_debug_text = sf::Text();
    m_debug_text.setFont(m_font);
    m_debug_text.setPosition(1060, 0);
    m_debug_text.setFillColor(sf::Color::Red);
    m_debug_text.setCharacterSize(20);

}

App::App() {
    m_clock = sf::Clock();
}

void App::MainLoop() {
    while (m_window->isOpen())
    {
        for (auto event = sf::Event{}; m_window->pollEvent(event);)
        {
            if (event.type == sf::Event::Closed)
            {
                m_window->close();
            }
            m_debug_text.setString(std::to_string(event.type));
        }

        // todo somehow pass events to Tick

        this->Tick();
        this->Render();
    }
}

