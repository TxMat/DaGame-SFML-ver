//
// Created by uranus on 29/05/24.
//

#include <cstring>
#include "NetworkManager.h"
#include "../../../Base/NetworkObject.h"
#include "../../../../Game/Objects/Gameplay/Ball.h"
#include "../../../Globals.h"

NetworkManager::NetworkManager(SceneManager *sm) :
	m_net(this),
    m_last_packet_ts(0),
	BaseManager(sm) {

	m_net.start();
    m_playerCount = 0;
}


void NetworkManager::FixedTick(float deltaTime) {
    for (auto& player : m_playerMap)
    {
        for (const auto& kv : m_replicatedObjectMap)
        {
            m_net.sendMessages(kv.second->GetNetworkPacket().ToVec(), player.first.first, player.first.second);
        }
    }
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

void NetworkManager::ReceiveMessage(std::vector<char>& bytes, char* ip, int* port) {
    const auto t = reinterpret_cast<const PacketType*>(bytes[0]);
    
    if (IS_CLIENT)
    {
        if (*t == PacketType::PosSync)
        {
            // Skip the message type and timestamp
            int index = 1 + sizeof(std::chrono::nanoseconds);
            std::chrono::nanoseconds ts;
            std::memcpy(&ts, &bytes[1], sizeof(std::chrono::nanoseconds));

            if (ts < m_last_packet_ts) {
                return;
            }

            m_last_packet_ts = ts;

            size_t uintSize = sizeof(unsigned int);

            // Extract ID
            unsigned int id;
            std::memcpy(&id, &bytes[index], uintSize);
            index += uintSize;

            // Prepare
            std::vector<uint8_t> payload(bytes.begin() + index, bytes.end());

            GetObjectToReplicate(id)->DeserializePayload(payload);
        }
    }
    else
    {
        std::pair<char*, int> pair = std::pair<char*, int>(ip, *port);
        auto iter = m_playerMap.find(pair);
        if (iter == m_playerMap.end())
        {
            if (m_playerCount == 4) return;

            m_playerMap[pair] = m_playerCount;
            m_playerCount++;
        }
        
        for (auto& var : m_playerMap)
        {
            if (var.first != pair)
            {
                m_net.sendMessages(bytes, var.first.first, var.first.second);
            }
        }
    }
    
}
