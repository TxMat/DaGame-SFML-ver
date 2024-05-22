#pragma once
#ifndef MAINNETWORK_H
#define MAINNETWORK_H

#include "UDPCommunicator.h"
#include <thread>
#include <iostream>

// fw decl
class SceneManager;

class MainNetwork {
public:
    explicit MainNetwork(SceneManager* sm);
    ~MainNetwork();

    void start();

private:
    UDPCommunicator udpComm;
    std::thread receiveThread;

    SceneManager* m_sm;

    void receiveMessages();
    void sendMessages(const std::string &msg, const std::string &addr);
};

#endif // MAINNETWORK_H