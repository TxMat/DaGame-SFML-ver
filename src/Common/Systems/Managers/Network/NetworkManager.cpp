//
// Created by uranus on 29/05/24.
//

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
	int index = 1 + sizeof(std::chrono::nanoseconds);
	size_t uintSize = sizeof(unsigned int);

	unsigned int id;
	std::memcpy(&id, &bytes[index], uintSize);

	GetObjectToReplicate(id)->DeserializePayload(bytes[index + uintSize])
}
