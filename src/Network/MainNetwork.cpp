#include "MainNetwork.h"

MainNetwork::MainNetwork() {
    // Initialisation du socket
    if (!udpComm.initSocket()) {
        std::cerr << "Erreur lors de l'initialisation du socket" << std::endl;
    }

    // Liaison du socket au port 8080
    if (!udpComm.bindSocket(8080)) {
        std::cerr << "Erreur lors de la liaison du socket au port 8080" << std::endl;
    }
}

MainNetwork::~MainNetwork() {
    // Arret du thread de reception
    // todo do not do this
    if (receiveThread.joinable()) {
        receiveThread.join();
    }
}

void MainNetwork::start() {


    //UDPCommunicator udpComm;

    //// Initialisation du socket
    //if (!udpComm.initSocket()) {
    //    std::cout << "No Init" << std::endl;

    //}

    //// Liaison du socket au port 8080
    //if (!udpComm.bindSocket(8080)) {
    //    std::cout << "No Bind" << std::endl;
    //}

    std::cout << "En attente de messages UDP sur le port 8080..." << std::endl;

    // Lancement du thread pour la reception de messages
    receiveThread = std::thread(&MainNetwork::receiveMessages, this);

    // Attend que le thread se termine
//    receiveThread.join();

}

void MainNetwork::receiveMessages() {
    while (true) {
        std::string receivedMessage;
        if (udpComm.receiveMessage(receivedMessage)) {
            std::cout << "Message recu: " << receivedMessage << std::endl;
        }
        else {
            std::cerr << "Erreur lors de la reception du message" << std::endl;
        }
    }
}

void MainNetwork::sendMessages(const std::string& msg, const std::string& addr)
{
    udpComm.sendMessage(msg, addr, 8080);
}