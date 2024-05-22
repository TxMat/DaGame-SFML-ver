#include "UDPCommunicator.h"
#include <iostream>
#include <cstring>

#ifdef _WIN32
#pragma comment(lib, "ws2_32.lib")
#endif

UDPCommunicator::UDPCommunicator() : sockfd(-1) {
#ifdef _WIN32
    WSADATA wsaData;
    if (WSAStartup(MAKEWORD(2, 2), &wsaData) != 0) {
        std::cerr << "Erreur lors de l'initialisation de Winsock" << std::endl;
    }
#endif
}

UDPCommunicator::~UDPCommunicator() {
    if (sockfd != -1) {
#ifdef _WIN32
        closesocket(sockfd);
        WSACleanup();
#else
        close(sockfd);
#endif
    }
}

bool UDPCommunicator::initSocket() {
    sockfd = socket(AF_INET, SOCK_DGRAM, IPPROTO_UDP);
    if (sockfd < 0) {
        std::cerr << "Erreur lors de la creation du socket" << std::endl;
        return false;
    }
    return true;
}

bool UDPCommunicator::bindSocket(int port) {
    sockaddr_in servaddr;
    std::memset(&servaddr, 0, sizeof(servaddr));

    servaddr.sin_family = AF_INET;
    servaddr.sin_addr.s_addr = INADDR_ANY;
    servaddr.sin_port = htons(port);

    if (bind(sockfd, (const struct sockaddr*)&servaddr, sizeof(servaddr)) < 0) {
        std::cerr << "Erreur lors de la liaison du socket" << std::endl;
#ifdef _WIN32
        closesocket(sockfd);
#else
        close(sockfd);
#endif
        return false;
    }
    return true;
}

bool UDPCommunicator::sendMessage(const std::string& message, const std::string& address, int port) {
    sockaddr_in servaddr;
    std::memset(&servaddr, 0, sizeof(servaddr));

    servaddr.sin_family = AF_INET;
    servaddr.sin_port = htons(port);
    servaddr.sin_addr.s_addr = inet_addr(address.c_str());

    if (sendto(sockfd, message.c_str(), message.length(), 0, (const struct sockaddr*)&servaddr, sizeof(servaddr)) < 0) {
        std::cerr << "Erreur lors de l'envoi du message" << std::endl;
        return false;
    }
    return true;
}

bool UDPCommunicator::receiveMessage(std::string& message, int bufferSize) {
    char buffer[1400];
    sockaddr_in cliaddr;
    socklen_t len = sizeof(cliaddr);

    int n = recvfrom(sockfd, buffer, bufferSize - 1, 0, (struct sockaddr*)&cliaddr, &len);
    if (n < 0) {
        std::cerr << "Erreur lors de la reception du message" << std::endl;
        return false;
    }

    buffer[n] = '\0';
    message = std::string(buffer);
    std::cout << message << std::endl;
    return true;
}