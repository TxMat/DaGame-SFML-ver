#pragma once
#ifndef MAINNETWORK_H
#define MAINNETWORK_H

#include "UDPCommunicator.h"
#include <thread>
#include <iostream>

class MainNetwork {
public:
    MainNetwork();
    ~MainNetwork();

    void start();

private:
    UDPCommunicator udpComm;
    std::thread receiveThread;

    void receiveMessages();
    void sendMessages(const std::string &msg, const std::string &addr);
};

#endif // MAINNETWORK_H