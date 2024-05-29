#pragma once
#ifndef MAINNETWORK_H
#define MAINNETWORK_H

#include "UDPCommunicator.h"
#include "SFML/System/Vector2.hpp"
#include <thread>
#include <iostream>

class NetworkManager;

class MainNetwork {
public:
    explicit MainNetwork(NetworkManager* nm);
    ~MainNetwork();

    void start();

private:
    UDPCommunicator udpComm;
    std::thread receiveThread;

    NetworkManager* m_nm;

    void receiveMessages();
    void sendMessages(const std::string &msg, const std::string &addr);

    void ParseMessage(const std::string &msg, std::string &objectName, sf::Vector2<float> &position);

    std::thread::native_handle_type m_h;
};

#endif // MAINNETWORK_H