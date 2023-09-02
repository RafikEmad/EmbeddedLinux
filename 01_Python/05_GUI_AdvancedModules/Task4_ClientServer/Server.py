import socket
import threading

# Function to handle client connections
def handle_client(client_socket):
    while True:
        data = client_socket.recv(1024)
        if not data:
            break
        client_socket.send(data)
    client_socket.close()

# Create a socket object
server = socket.socket(socket.AF_INET, socket.SOCK_STREAM)

# Bind the socket to a specific address and port
server.bind(('0.0.0.0', 8888))

# Start listening for incoming connections
server.listen(5)  # Maximum number of queued connections

print("[*] Listening on 0.0.0.0:8888")

while True:
    client, addr = server.accept()
    print(f"[*] Accepted connection from: {addr[0]}:{addr[1]}")

    # Start a new thread to handle the client
    client_handler = threading.Thread(target=handle_client, args=(client,))
    client_handler.start()
