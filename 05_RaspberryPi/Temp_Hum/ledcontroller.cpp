#include "ledcontroller.hpp"
#include <iostream>
#include <fstream>
#include <unistd.h>
#include <cstdlib>

LedController::LedController(const std::string& ledPath) : ledPath(ledPath) {
    setTriggerPermissions();
}

void LedController::setTriggerPermissions() {
    std::string triggerFile = ledPath + "/trigger";
    std::string command = "sudo chmod 777 " + triggerFile;

    // Execute the command using the system() function
    int result = system(command.c_str());

    // Check the result of the system command
    if (result != 0) {
        std::cerr << "Error setting permissions for trigger file: " << triggerFile << std::endl;
    }
}

void LedController::setTrigger(const std::string& trigger) {
    std::string triggerFile = ledPath + "/trigger";
    std::ofstream file(triggerFile);

    if (file.is_open()) {
        file << trigger;
        file.close();
    } else {
        std::cerr << "Error opening trigger file: " << triggerFile << std::endl;
    }
}

void LedController::blink(int durationSeconds) {
    setTrigger("timer");
    sleep(durationSeconds);
    setTrigger("none");
}
