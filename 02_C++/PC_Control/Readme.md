# ControlPC

ControlPC is a WebSocket-based remote control application for controlling your Linux PC from a web interface.

## Features

- **Terminal**: Open the terminal on your Linux PC remotely.
- **Web Browser**: Open a web browser and navigate to a specified URL.
- **Volume Control**: Adjust the system volume, including volume up, volume down, mute, and unmute.
- **Battery Status**: Check the battery percentage of your Linux laptop.
- **Home Directory**: Open the home directory on your PC.

## Getting Started

### Prerequisites

- [C++](https://en.cppreference.com/w/)
- [WebSocket++](https://github.com/zaphoyd/websocketpp)
- [ALSA](https://www.alsa-project.org/)

### Building
1. Clone websocket++ repo
    ```bash
    git clone https://github.com/zaphoyd/websocketpp.git

2. Build WebSocket++
    ```bash
    cd websocketpp
3. Create a build directory and navigate to it
    ```bash
    mkdir build
    cd build
4. Use cmake to configure the build:
    ```bash
    cmake ..
5. Use make to build the library:
    ```bash
    make
6. Install WebSocket++ Headers (Optional for easy include):
    ```bash
    sudo make install
7. for volume control install ALSA Development Libraries
    ```bash
    sudo apt-get install libasound2-dev
8. compile
    ```bash
    g++ -o control control.cpp -lasound
    ./control
