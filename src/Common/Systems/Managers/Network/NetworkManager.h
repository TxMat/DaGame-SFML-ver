//
// Created by uranus on 29/05/24.
//

#ifndef CMAKESFMLPROJECT_NETWORKMANAGER_H
#define CMAKESFMLPROJECT_NETWORKMANAGER_H


#include "../Base/BaseManager.h"
#include "../../../Base/Object.h"

class NetworkManager : public BaseManager {

public:

    explicit NetworkManager(SceneManager *sm);

    void FixedTick(float deltaTime) override;

    void AddObjectToReplicate(Object *object);

    void UnrestrictedTick(float deltaTime) override;

    void Render(sf::RenderWindow &window) override;

protected:

    std::vector<Object *> m_replicatedObjectList = std::vector<Object *>();

};


#endif //CMAKESFMLPROJECT_NETWORKMANAGER_H
