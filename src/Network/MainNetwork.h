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
    void sendMessages(std::string msg);
};

#endif // MAINNETWORK_H