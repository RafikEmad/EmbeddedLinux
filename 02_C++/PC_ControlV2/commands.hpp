#ifndef COMMANDS_H
#define COMMANDS_H

#include <string>
#include <sys/socket.h>
#include <cstring>
#include <iostream>
#include <cstdlib>
#include <fstream>
#include <streambuf>
#include <functional>
#include <map>

class Commands {
public:
    // Define function type alias for actions associated with commands
    using CommandFunction = std::function<void()>;
    Commands(int clientSocket);
    ~Commands();

    void ExecuteCommand(const std::string& command);

private:
    // Define your command-handling functions as private methods.
    void OpenTerminal();
    void OpenHomeDirectory();
    void OpenChrome();
    void GetBatteryPercentage();
    void ExecuteAndSendOutput(const char* command);
    int clientSocket;
    std::map<std::string, CommandFunction> commandMap;
};

#endif
