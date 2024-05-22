//
// Created by uranus on 22/05/24.
//

#include "AppClient.h"
#include "Game/Objects/Gameplay/Paddle.h"
#include "Game/Objects/Gameplay/Ball.h"
#include "Common/Globals.h"
#include "Game/Objects/UI/Debug/FPSCounter.h"
#include "Game/Objects/UI/Debug/DTFixedTime.h"
#include "Game/Objects/UI/Debug/DT.h"

AppClient::AppClient() = default;

void AppClient::Init() {
    // todo use smart ptr
    Object* playerOnePaddle = new Paddle(1, 10, 100);
    m_sceneManager.AddObjectToScene(playerOnePaddle);

    Object* playerTwoPaddle = new Paddle(2, 10, 100);
    m_sceneManager.AddObjectToScene(playerTwoPaddle);

    Object* playerThreePaddle = new Paddle(3, 100, 10);
    m_sceneManager.AddObjectToScene(playerThreePaddle);

    Object* playerFourPaddle = new Paddle(4, 100, 10);
    m_sceneManager.AddObjectToScene(playerFourPaddle);

    //    Object *ball = new Ball(1000, 10);
    //    ball->getMShape()->setPosition(WIDTH / 2, HEIGHT / 2);
    //    m_sceneManager.AddObjectToScene(ball);

    Object* ball = new Ball(1000, 10);
    ball->getMShape()->setPosition(WIDTH / 2, HEIGHT / 2);
    m_sceneManager.AddObjectToScene(ball);
    m_sceneManager.AddObjectToReplicate(ball, (std::string &) "Ball");

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

void AppClient::MainLoop() {

}


