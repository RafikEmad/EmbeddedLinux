#include "commands.hpp"

Commands::Commands(int clientSocket) : clientSocket(clientSocket) {}
  
Commands::~Commands() {
    // Clean up any resources if necessary.
}

void Commands::ExecuteCommand(const std::string& command) {
    if (command == "terminal") {
        OpenTerminal();
    } 
    else if (command == "home"){
        OpenHomeDirectory();
    }    
    else if (command == "chrome"){
        OpenChrome();
    } 
    else if (command == "battery"){
        GetBatteryPercentage();
    }
    else {
        // Handle other commands or provide an error message.
        std::cerr << "Unknown command: " << command << std::endl;
    }
}

void Commands::OpenHomeDirectory() {
    const char* command = "xdg-open $HOME";
    //system("xdg-open $HOME");
    ExecuteAndSendOutput(command);
}

void Commands::GetBatteryPercentage() {
    const char* command = "upower -i /org/freedesktop/UPower/devices/battery_BAT0 | grep 'percentage:' | awk '{print $2}'";
    //system("upower -i /org/freedesktop/UPower/devices/battery_BAT0 | grep 'percentage:' | awk '{print $2}'");
    ExecuteAndSendOutput(command);
}

void Commands::OpenChrome() {
    const char* command = "google-chrome";
    //system("google-chrome");
    ExecuteAndSendOutput(command);
}

void Commands::OpenTerminal() {
    const char* command = "x-terminal-emulator";
    ExecuteAndSendOutput(command);
    //std::cout << "Opening terminal..." << std::endl;
    //system("gnome-terminal"); // Example: Opens a GNOME terminal. Adjust as needed.
}

void Commands::ExecuteAndSendOutput(const char* command) {
        // Execute the command and capture its output
        FILE* pipe = popen(command, "r");
        if (pipe) {
            char buffer[128];
            std::string result = "";
            while (!feof(pipe)) {
                if (fgets(buffer, 128, pipe) != NULL) {
                    result += buffer;
                }
            }
            pclose(pipe);

            // Send the captured output back to the client
            send(clientSocket, result.c_str(), result.size(), 0);
        } else {
            const char* error = "Error executing the command\n";
            send(clientSocket, error, strlen(error), 0);
        }
    }