#ifndef UDPCOMMUNICATOR_H
#define UDPCOMMUNICATOR_H

#include <string>

// Definition des includes et des types pour Windows et Unix/Linux
#ifdef _WIN32
#include <winsock2.h>
#include <ws2tcpip.h>
typedef SOCKET socket_t;
typedef int socklen_t;
#else
#include <arpa/inet.h>
#include <unistd.h>
typedef int socket_t;
#endif

class UDPCommunicator {
public:
    UDPCommunicator();
    ~UDPCommunicator();

    bool initSocket();
    bool bindSocket(int port);
    bool sendMessage(const std::string& message, const std::string& address, int port);
    bool receiveMessage(std::string& message, int bufferSize = 1024, PSTR ip, int* port);

private:
    socket_t sockfd;
};

#endif // UDPCOMMUNICATOR_H