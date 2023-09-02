import socket
import time

# Create a socket object
client = socket.socket(socket.AF_INET, socket.SOCK_STREAM)

# Connect to the server
client.connect(('localhost', 8888))

while True:
    try:
        # Send data to the server
        client.send(b"Hello from Client 1")

        # Receive and print the server's response
        response = client.recv(1024)
        print("Client 1 received:", response.decode())

        # Sleep for a while before sending the next message
        time.sleep(5)  # Adjust the sleep duration as needed
    except Exception as e:
        print("Client error:", str(e))
