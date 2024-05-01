//
// Created by uranus on 4/24/24.
//

#include "SFML/System.hpp"
#include "SFML/Graphics.hpp"
#include "Common/Base/Object.h"
#include "Common/Systems/Managers/SceneManager.h"

#ifndef CMAKESFMLPROJECT_APP_H
#define CMAKESFMLPROJECT_APP_H


class App {

public:
    App();

    void Init();

    void MainLoop();

private:

    SceneManager m_sceneManager;
};


#endif //CMAKESFMLPROJECT_APP_H
