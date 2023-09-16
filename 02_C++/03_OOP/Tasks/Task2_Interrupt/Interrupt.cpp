#include <iostream>
#include <csignal> // for signal handling

// Signal handler function
void signalHandler(int signal) {
    if (signal == SIGINT) {
        std::cout << "Ctrl+C signal received. Handling the interrupt..." << std::endl;
        // Add your custom handling logic here
        exit(signal);
    }
}

int main() {
    // Set up the signal handler for SIGINT (Ctrl+C)
    signal(SIGINT, signalHandler);

    std::cout << "Press Ctrl+C to trigger an interrupt..." << std::endl;

    // Your program logic goes here

    while (true) {
        // Your main program logic continues running
    }

    return 0;
}
