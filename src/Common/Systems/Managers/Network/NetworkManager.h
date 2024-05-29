//
// Created by uranus on 29/05/24.
//

#ifndef CMAKESFMLPROJECT_NETWORKMANAGER_H
#define CMAKESFMLPROJECT_NETWORKMANAGER_H

#include "../Base/BaseManager.h"
#include "../../../Base/Object.h"
#include "../../../../Network/MainNetwork.h"

class NetworkManager : public BaseManager {

public:

    explicit NetworkManager(SceneManager *sm);

    void FixedTick(float deltaTime) override;

    void AddObjectToReplicate(Object *object);
    Object* GetObjectToReplicate(std::string& name);

    void UnrestrictedTick(float deltaTime) override;

    void Render(sf::RenderWindow &window) override;

protected:

    std::vector<Object *> m_replicatedObjectList = std::vector<Object *>();

    MainNetwork m_net;

};


#endif //CMAKESFMLPROJECT_NETWORKMANAGER_H
