#include "SFML/Graphics.hpp"
#include "Game/MainScene.h"
#include <iostream>

#include "App.h"
#include "Network/UDPCommunicator.h"
#include "Common/Globals.h"

int main() {

    UDPCommunicator udpComm;

    // Initialisation du socket
    if (!udpComm.initSocket()) {
        return -1;
    }

    // Liaison du socket au port 8080
    if (!udpComm.bindSocket(8080)) {
        return -1;
    }

    // Envoi d'un message
    if (udpComm.sendMessage("Bonjour", "127.0.0.1", 8080)) {
        //std::count << "Message envoy�: Bonjour, UDP!" << std::endl;
    }


    while (true) {
        std::string receivedMessage;
        if (udpComm.receiveMessage(receivedMessage)) {
            std::cout << "Message re�u: TTTT " << receivedMessage << std::endl;
        }
        else {
            std::cerr << "Erreur lors de la r�ception du message" << std::endl;
        }
    }

    

    return 0;

    
    /*auto app = App();
    app.Init();
    app.MainLoop();*/
    
}