# PC Control

## Overview

This project demonstrates a simple client-server architecture using C++. The server, implemented in C++, listens for incoming connections and responds to various commands sent by a client. The commands can be used to perform actions on the server, such as opening applications, retrieving system information, and more.

## Project Structure

The project is structured into the following components:

### server.hpp and server.cpp

- `server.hpp` defines the `Server` class, which is responsible for setting up a socket, listening for connections, and handling client requests.
- `server.cpp` contains the implementation of the `Server` class.

### commands.hpp and commands.cpp

- `commands.hpp` defines the `Commands` class, which manages the execution of various commands received from the client.
- `commands.cpp` contains the implementation of the `Commands` class.

### Mobile App

A mobile app, or any client, can connect to the server using its IP address and port. The client can send commands to the server to trigger various actions.

## How to Use the Mobile App

1. **Install the Mobile App:** Install a mobile app (or any client) capable of making HTTP requests to a specific IP address and port.

2. **Connect to the Server:** In the mobile app, specify the IP address and port of the server. The server should be running on a reachable local network. For example, you can use the server's local IP address (e.g., 192.168.1.x).

3. **Send Commands:** Use the mobile app to send HTTP requests with various commands to the server. The server will process these commands and perform corresponding actions.

## Compiling and Running the Project

To compile and run the project, follow these steps:

1. **Clone the Repository:** Clone the project repository to your local machine.

2. **Compile the Code:** In the project directory, open a terminal and run the following command to compile the server and commands:
    ```bash
        g++ -o server server.cpp commands.cpp main.cpp

3. **Run the Server:** Start the server by running the following command:
    ```bash
        ./server

4. **Use the Mobile App:** Use the mobile app (or any client) to connect to the server using its local IP address and port. Send commands to the server to trigger actions.

## Example Commands

Here are some example commands you can send from the mobile app:

- `terminal`: Open a terminal or command prompt on the server.
- `home`: Open the user's home directory.
- `chrome`: Open a web browser, such as Chrome, on the server.
- `battery`: Retrieve the battery percentage on the server (if supported).
