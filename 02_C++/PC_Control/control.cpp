#include <iostream>
#include <cstring>
#include <sys/socket.h>
#include <netinet/in.h>
#include <unistd.h>

// Define a port number to listen on
#define PORT 8080

int main() {
    int serverSocket, clientSocket;
    struct sockaddr_in serverAddr, clientAddr;
    socklen_t addrLen = sizeof(clientAddr);

    // Create socket
    serverSocket = socket(AF_INET, SOCK_STREAM, 0);
    if (serverSocket == -1) {
        perror("Error creating socket");
        return 1;
    }

    // Prepare the server address structure
    memset(&serverAddr, 0, sizeof(serverAddr));
    serverAddr.sin_family = AF_INET;
    serverAddr.sin_port = htons(PORT);
    serverAddr.sin_addr.s_addr = INADDR_ANY;

    // Bind the socket to the address and port
    if (bind(serverSocket, (struct sockaddr*)&serverAddr, sizeof(serverAddr)) == -1) {
        perror("Error binding socket");
        return 1;
    }

    // Listen for incoming connections
    if (listen(serverSocket, 5) == -1) {
        perror("Error listening");
        return 1;
    }

    std::cout << "Server is listening on port " << PORT << std::endl;

    // Accept incoming connections
    clientSocket = accept(serverSocket, (struct sockaddr*)&clientAddr, &addrLen);
    if (clientSocket == -1) {
        perror("Error accepting connection");
        return 1;
    }

    std::cout << "Client connected" << std::endl;

    char buffer[1024];
    while (true) {
        // Receive data from the client
        memset(buffer, 0, sizeof(buffer));
        int bytesRead = recv(clientSocket, buffer, sizeof(buffer), 0);
        if (bytesRead <= 0) {
            std::cerr << "Connection closed by client" << std::endl;
            break;
        }

        // Process the received data (implement your logic here)
        std::cout << "Received: " << buffer << std::endl;

        // You can execute commands on your laptop based on the received data.
        // For example, you can use system() to run system commands.

        // Send a response back to the client if needed
        // send(clientSocket, response, strlen(response), 0);
    }

    // Close the sockets
    close(clientSocket);
    close(serverSocket);

    return 0;
}
