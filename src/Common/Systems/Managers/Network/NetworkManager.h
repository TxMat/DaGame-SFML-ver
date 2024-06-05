//
// Created by uranus on 29/05/24.
//

#ifndef CMAKESFMLPROJECT_NETWORKMANAGER_H
#define CMAKESFMLPROJECT_NETWORKMANAGER_H

#include "../Base/BaseManager.h"
#include "../../../Base/Object.h"
#include "../../../../Network/MainNetwork.h"
#include "../../../Base/NetworkObject.h"

class NetworkManager : public BaseManager {

public:

    explicit NetworkManager(SceneManager *sm);

    void FixedTick(float deltaTime) override;

    void AddObjectToReplicate(NetworkObject *object);
    NetworkObject* GetObjectToReplicate(unsigned int id);

    void UnrestrictedTick(float deltaTime) override;

    void Render(sf::RenderWindow &window) override;

    void ReceiveMessage(std::vector<char>& bytes, char* ip, int* port);

protected:

    std::map<std::pair<char*, int>, int> m_playerMap = std::map<std::pair<char*, int>, int>();
    std::map<unsigned int, NetworkObject *> m_replicatedObjectMap = std::map<unsigned int, NetworkObject *>();

    MainNetwork m_net;

private:

    std::chrono::nanoseconds m_last_packet_ts;

};


#endif //CMAKESFMLPROJECT_NETWORKMANAGER_H
