//
// Created by uranus on 29/05/24.
//

#include "NetworkManager.h"

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

void NetworkManager::AddObjectToReplicate(Object *object) {

}

Object* NetworkManager::GetObjectToReplicate(std::string& name){

}
