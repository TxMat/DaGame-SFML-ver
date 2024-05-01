//
// Created by uranus on 4/24/24.
//

#include <cmath>
#include <iostream>
#include "App.h"
#include "Game/Objects/Ball.h"
#include "Game/Objects/Paddle.h"
#include "Common/Globals.h"

void App::Tick() {

    m_sceneManager.Tick();

//    m_currentTime = m_clock.getElapsedTime();
//    double fps = 1.0f / (m_currentTime.asSeconds() - m_lastTime.asSeconds()); // the asSeconds returns a float
//    m_fps.setString(std::string("Fps : " + std::to_string(floor(fps))));
//    m_lastTime = m_currentTime;
}

void App::Init() {

    // todo use smart ptr
    Object *playerOnePaddle = new Paddle(1);
    m_sceneManager.AddToScene(playerOnePaddle);

    Object *playerTwoPaddle = new Paddle(2);
    m_sceneManager.AddToScene(playerTwoPaddle);

    Object *ball = new Ball(5, 10);
    ball->getMShape()->setPosition(WIDTH / 2, HEIGHT / 2);
    m_sceneManager.AddToScene(ball);

    if (!m_font.loadFromFile("Montserrat-SemiBold.ttf")) {
        printf("failed");
    }

    printf("OK");

//    m_fps = sf::Text();
//    m_fps.setFont(m_font);
//    m_fps.setFillColor(sf::Color::Green);
//    m_fps.setCharacterSize(20);
//    m_window->draw(m_fps);

    m_debug_text = sf::Text();
    m_debug_text.setFont(m_font);
    m_debug_text.setPosition(1060, 0);
    m_debug_text.setFillColor(sf::Color::Red);
    m_debug_text.setCharacterSize(20);

}

App::App() : m_sceneManager(SceneManager()) {
    m_clock = sf::Clock();

}

void App::MainLoop() {
    while (m_sceneManager.isRunning) {
        m_sceneManager.Tick();
    }
}

