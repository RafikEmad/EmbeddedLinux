#include "server.hpp"

int main() {
    Server server;
    
    if (server.CreateSocket(8080) && server.Bind() && server.ListenForConnections()) {
        server.StartConnection();
    }
    
    return 0;
}
