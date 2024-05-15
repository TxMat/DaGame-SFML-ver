#include <iostream>
#include <cstring>
#include "UDPCommunicator.h"

class UDPCommunicator {
public:
    UDPCommunicator() : sockfd(-1) {}

    ~UDPCommunicator() {
        if (sockfd != -1) {
            closesocket(sockfd);
        }
    }

    bool initSocket() {
        sockfd = socket(AF_INET, SOCK_DGRAM, 0);
        if (sockfd < 0) {
            std::cerr << "Erreur lors de la création du socket" << std::endl;
            return false;
        }
        return true;
    }

    bool bindSocket(int port) {
        sockaddr_in servaddr;
        memset(&servaddr, 0, sizeof(servaddr));

        servaddr.sin_family = AF_INET;
        servaddr.sin_addr.s_addr = INADDR_ANY;
        servaddr.sin_port = htons(port);

        if (bind(sockfd, (const struct sockaddr*)&servaddr, sizeof(servaddr)) < 0) {
            std::cerr << "Erreur lors de la liaison du socket" << std::endl;
            close(sockfd);
            return false;
        }
        return true;
    }

    bool sendMessage(const std::string& message, const std::string& address, int port) {
        sockaddr_in servaddr;
        memset(&servaddr, 0, sizeof(servaddr));

        servaddr.sin_family = AF_INET;
        servaddr.sin_port = htons(port);
        servaddr.sin_addr.s_addr = inet_addr(address.c_str());

        if (sendto(sockfd, message.c_str(), message.length(), 0, (const struct sockaddr*)&servaddr, sizeof(servaddr)) < 0) {
            std::cerr << "Erreur lors de l'envoi du message" << std::endl;
            return false;
        }
        return true;
    }

    bool receiveMessage(std::string& message, int bufferSize = 1024) {
        char buffer[bufferSize];
        sockaddr_in cliaddr;
        socklen_t len = sizeof(cliaddr);

        int n = recvfrom(sockfd, buffer, bufferSize - 1, 0, (struct sockaddr*)&cliaddr, &len);
        if (n < 0) {
            std::cerr << "Erreur lors de la réception du message" << std::endl;
            return false;
        }

        buffer[n] = '\0';
        message = std::string(buffer);
        return true;
    }

private:
    int sockfd;
};