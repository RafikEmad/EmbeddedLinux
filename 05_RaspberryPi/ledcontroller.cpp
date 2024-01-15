#include "ledcontroller.hpp"
#include <iostream>
#include <fstream>
#include <unistd.h>

LedController::LedController(const std::string& ledPath) : ledPath(ledPath) {}

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
