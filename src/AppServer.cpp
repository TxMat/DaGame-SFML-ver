//
// Created by uranus on 4/24/24.
//

#include <cmath>
#include <iostream>
#include "AppServer.h"
#include "Game/Objects/Gameplay/Ball.h"
#include "Game/Objects/Gameplay/Paddle.h"
#include "Common/Globals.h"
#include "Game/Objects/UI/Debug/FPSCounter.h"
#include "Game/Objects/UI/Debug/DT.h"
#include "Game/Objects/UI/Debug/DTFixedTime.h"
#include "Game/Objects/UI/Score/ScoreUi.h"
#include "Network/MainNetwork.h"

void AppServer::Init() {

    // todo use smart ptr
    Object *playerOnePaddle = new Paddle(1, 10, 100);
    m_sceneManager.AddObjectToScene(playerOnePaddle);

    Object *playerTwoPaddle = new Paddle(2, 10, 100);
    m_sceneManager.AddObjectToScene(playerTwoPaddle);

    Object* playerThreePaddle = new Paddle(3, 100, 10);
    m_sceneManager.AddObjectToScene(playerThreePaddle);

    Object* playerFourPaddle = new Paddle(4, 100, 10);
    m_sceneManager.AddObjectToScene(playerFourPaddle);

//    Object *ball = new Ball(1000, 10);
//    ball->getMShape()->setPosition(WIDTH / 2, HEIGHT / 2);
//    m_sceneManager.AddObjectToScene(ball);

    for (int i = 0; i < 10; ++i) {
        Object *ball = new Ball(1000, 10);
        ball->getMShape()->setPosition(WIDTH / 2, HEIGHT / 2);
        m_sceneManager.AddObjectToScene(ball);
    }

//    Object *ball2 = new Ball(1000, 10);
//    ball->getMShape()->setPosition(WIDTH / 2, HEIGHT / 2);
//    m_sceneManager.AddObjectToScene(ball2);

    auto fps = new FPSCounter();
    auto DT = new class DT();
    auto DT_FixedUpdate = new DTFixedTime();


    m_sceneManager.AddUIToScene(fps, true);
    m_sceneManager.AddUIToScene(DT, true);
    m_sceneManager.AddUIToScene(DT_FixedUpdate, false);

}

AppServer::AppServer() : m_sceneManager(SceneManager(true)) {
}

void AppServer::MainLoop() {
    while (m_sceneManager.isRunning) {
        m_sceneManager.UnrestrictedTick();
    }
}

