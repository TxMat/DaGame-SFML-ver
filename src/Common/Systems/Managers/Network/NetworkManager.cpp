//
// Created by uranus on 29/05/24.
//

#include <cstring>
#include "NetworkManager.h"
#include "../../../Base/NetworkObject.h"
#include "../../../../Game/Objects/Gameplay/Ball.h"

NetworkManager::NetworkManager(SceneManager *sm) :
	m_net(this),
	BaseManager(sm) {

	m_net.start();
}

void NetworkManager::FixedTick(float deltaTime) {

}

void NetworkManager::UnrestrictedTick(float deltaTime) {

}

void NetworkManager::Render(sf::RenderWindow &window) {

}

void NetworkManager::AddObjectToReplicate(NetworkObject *object) {

}

NetworkObject* NetworkManager::GetObjectToReplicate(unsigned int id){
	return m_replicatedObjectMap[id];
}

void NetworkManager::ReceiveMessage(std::vector<char>& bytes) {
    const auto t = reinterpret_cast<const PacketType*>(bytes[0]);
    
    if (*t == PacketType::Conn)
    {

    }
    else if (*t == PacketType::PosSync)
    {
        // Skip the message type and timestamp
        int index = 1 + sizeof(std::chrono::nanoseconds);
        size_t uintSize = sizeof(unsigned int);

        // Extract ID
        unsigned int id;
        std::memcpy(&id, &bytes[index], uintSize);
        index += uintSize;

        // Prepare wtf
        std::vector<uint8_t> payload(bytes.begin() + index, bytes.end());

        GetObjectToReplicate(id)->DeserializePayload(payload);
    }
}
