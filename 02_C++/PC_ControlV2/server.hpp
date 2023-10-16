#ifndef SERVER_H
#define SERVER_H

#include <iostream>
#include <arpa/inet.h>
#include <cstring>
#include <sys/socket.h>
#include <unistd.h>
#include "commands.hpp"

class Server {
public:
    Server();
    ~Server();

    bool CreateSocket(int port);
    bool Bind();
    bool ListenForConnections();
    void StartConnection();
    void Options();
private:
    int serverSocket;
    int clientSocket;
    struct sockaddr_in serverAddr;
    struct sockaddr_in clientAddr;
    socklen_t addrLen;
};

#endif
