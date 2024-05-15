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
    // Arrêt du thread de réception
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

    // Lancement du thread pour la réception de messages
    receiveThread = std::thread(&MainNetwork::receiveMessages, this);

    // Attend que le thread se termine
    receiveThread.join();

}

void MainNetwork::receiveMessages() {
    while (true) {
        std::string receivedMessage;
        if (udpComm.receiveMessage(receivedMessage)) {
            std::cout << "Message reçu: " << receivedMessage << std::endl;
        }
        else {
            std::cerr << "Erreur lors de la réception du message" << std::endl;
        }
    }
}