#ifndef LOG_HPP
#define LOG_HPP

#include <iostream>
#include <fstream>
#include <vector>
#include <string>

class LOG {
public:
    enum Level {
        debug,
        info,
        warn,
        error
    };

    LOG(Level logLevel, const std::string& fileName = "");

    template <typename T>
    LOG& operator<<(const std::pair<Level, T>& logMessage);

    static void Dump();
    static void Clear();
    static void SetLogLevel(Level level);

private:
    Level logLevel;
    static Level currentLevel;
    static std::vector<std::pair<Level, std::string>> buffer;
    static std::string logFileName;
    static std::ofstream logFile;
};
template <typename T>
LOG& LOG::operator<<(const std::pair<Level, T>& logMessage) {
    if (currentLevel >= logMessage.first) {
        buffer.emplace_back(logMessage.first, logMessage.second);
        // if (logFile.is_open()) {
        //     logFile << logMessage.second << std::endl;
        // }
    }
    return *this;
}
#endif
