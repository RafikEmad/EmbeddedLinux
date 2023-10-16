#include "server.hpp"

Server::Server() {
    // Initialize any member variables if needed
    addrLen = sizeof(struct sockaddr_in);
}

Server::~Server() {
    // Clean up resources if needed
    close(serverSocket);
    // Optionally, close the clientSocket if necessary
}

bool Server::CreateSocket(int port) {
    serverSocket = socket(AF_INET, SOCK_STREAM, 0);
    if (serverSocket == -1) {
        perror("Error creating socket");
        return false;
    }

    serverAddr.sin_family = AF_INET;
    serverAddr.sin_port = htons(port);
    serverAddr.sin_addr.s_addr = INADDR_ANY;

    return true;
}

bool Server::Bind() {
    if (bind(serverSocket, (struct sockaddr*)&serverAddr, sizeof(serverAddr))) {
        perror("Error binding socket");
        return false;
    }
    return true;
}

bool Server::ListenForConnections() {
    if (listen(serverSocket, 1) == -1) {
        perror("Error listening for connections");
        return false;
    }
    return true;
}

void Server::Options() {
    const char* welcomeMessage = "Welcome to the server!\nChoose one of the following:\nterminal\nhome\nchrome\nbattery";
    send(clientSocket, welcomeMessage, strlen(welcomeMessage), 0);
}

void Server::StartConnection() {
    // Accept a single connection
    clientSocket = accept(serverSocket, (struct sockaddr*)&clientAddr, &addrLen);
    std::cout << "Connection accepted from " << inet_ntoa(clientAddr.sin_addr) << std::endl;
    
    char buffer[1024];
    
    // Optionally, send a message to the client
    this->Options();
    Commands commands(clientSocket);
    while (true) {
        int bytesRead = recv(clientSocket, buffer, sizeof(buffer), 0);
        
        if (bytesRead <= 0) {
            // Handle disconnection or error
            break;
        } else {
            // Null-terminate the received data to treat it as a C-style string
            buffer[bytesRead] = '\0';
            // Print the received string
            std::cout << "Received: " << buffer << std::endl;
        }
        std::string receivedCommand(buffer, bytesRead);
        std::cout << receivedCommand << std::endl;

        // Remove leading and trailing whitespace
        receivedCommand.erase(receivedCommand.find_last_not_of(" \t\n\r\f\v") + 1);
        receivedCommand.erase(0, receivedCommand.find_first_not_of(" \t\n\r\f\v"));
        commands.ExecuteCommand(receivedCommand);
        this->Options();
    }
    
    // Optionally, you can close the connection when done
    // close(clientSocket);
}

