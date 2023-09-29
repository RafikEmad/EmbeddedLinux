#include "Log.hpp"

LOG::Level LOG::currentLevel = LOG::warn;
std::vector<std::pair<LOG::Level, std::string>> LOG::buffer;
std::string LOG::logFileName;
std::ofstream LOG::logFile;

LOG::LOG(Level logLevel, const std::string& fileName) : logLevel(logLevel) {
    if (!logFileName.empty() && !logFile.is_open()) {
        logFile.open(logFileName);
    }
    if (!fileName.empty()) {
        logFileName = fileName;
        logFile.open(logFileName);
    }
}



void LOG::Dump() {
    if (logFile.is_open()) {
        logFile << "Log Message" << std::endl;
        for (const auto& logMsg : buffer) {
            if (currentLevel >= logMsg.first) {
                logFile << logMsg.second << std::endl;
            }
        }
    }

    for (const auto& logMsg : buffer) {
        if (currentLevel >= logMsg.first) {
            std::cout << logMsg.second << std::endl;
        }
    }
}

void LOG::Clear() {
    buffer.clear();
}

void LOG::SetLogLevel(Level level) {
    currentLevel = level;
}
