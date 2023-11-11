#include <iostream>
#include <csignal>
#include <cstdlib>
#include <thread>
#include <chrono>

void handleInterrupt() {
    std::cout << "Exit signal received. Exiting..." << std::endl;
    std::exit(EXIT_FAILURE);
}

int main() {
    std::signal(SIGINT, [](int){ handleInterrupt(); });

    std::cout << "This is a running process. Press Ctrl+C to interrupt." << std::endl;

    // Simulating a long-running process
    for (int i = 0; i < 10; ++i) {
        std::cout << "Working... " << i << std::endl;
        std::this_thread::sleep_for(std::chrono::seconds(1));
    }

    std::cout << "Process completed successfully." << std::endl;

    return EXIT_SUCCESS;
}