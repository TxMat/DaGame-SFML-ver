//
// Created by uranus on 4/24/24.
//

#include <cmath>
#include <iostream>
#include "App.h"
#include "Game/Objects/Gameplay/Ball.h"
#include "Game/Objects/Gameplay/Paddle.h"
#include "Common/Globals.h"
#include "Game/Objects/UI/Debug/FPSCounter.h"
#include "Game/Objects/UI/Debug/DT.h"

void App::Init() {

    // todo use smart ptr
    Object *playerOnePaddle = new Paddle(1);
    m_sceneManager.AddObjectToScene(playerOnePaddle);

    Object *playerTwoPaddle = new Paddle(2);
    m_sceneManager.AddObjectToScene(playerTwoPaddle);

    Object *ball = new Ball(1000, 10);
    ball->getMShape()->setPosition(WIDTH / 2, HEIGHT / 2);
    m_sceneManager.AddObjectToScene(ball);

    auto fps = new FPSCounter();
    auto DT = new class DT();

    m_sceneManager.AddUIToScene(fps, true);
    m_sceneManager.AddUIToScene(DT, true);

}

App::App() : m_sceneManager(SceneManager()) {
}

void App::MainLoop() {
    while (m_sceneManager.isRunning) {
        m_sceneManager.UnrestrictedTick();
    }
}

