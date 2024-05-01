//
// Created by uranus on 4/24/24.
//

#include <cmath>
#include <iostream>
#include "App.h"
#include "Game/Objects/Gameplay/Ball.h"
#include "Game/Objects/Gameplay/Paddle.h"
#include "Common/Globals.h"
#include "Game/Objects/UI/FPSCounter.h"

void App::Tick() {
    m_sceneManager.Tick();
}

void App::Init() {

    // todo use smart ptr
    Object *playerOnePaddle = new Paddle(1);
    m_sceneManager.AddObjectToScene(playerOnePaddle);

    Object *playerTwoPaddle = new Paddle(2);
    m_sceneManager.AddObjectToScene(playerTwoPaddle);

    Object *ball = new Ball(5, 10);
    ball->getMShape()->setPosition(WIDTH / 2, HEIGHT / 2);
    m_sceneManager.AddObjectToScene(ball);

    auto fps = new FPSCounter();
    m_sceneManager.AddUIToScene(fps);


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

