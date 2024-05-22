//
// Created by uranus on 22/05/24.
//

#ifndef CMAKESFMLPROJECT_APPCLIENT_H
#define CMAKESFMLPROJECT_APPCLIENT_H


#include "Common/Systems/Managers/SceneManager.h"

class AppClient {

public:

    AppClient();

    void Init();

    void MainLoop();

private:

    SceneManager m_sceneManager = SceneManager(false);

};


#endif //CMAKESFMLPROJECT_APPCLIENT_H
