#include <iostream>
#include <websocketpp/config/asio_no_tls.hpp>
#include <websocketpp/server.hpp>
#include <cstdlib>
#include <alsa/asoundlib.h>
#include <cstring>
#include <map>
#include <functional>

#if defined(__linux__)
#include <fstream>
#endif

using server_t = websocketpp::server<websocketpp::config::asio>;

class ControlPC {
public:
    ControlPC() {
        // Initialize the WebSocket server
        server_.init_asio();
        server_.set_message_handler(std::bind(&ControlPC::on_message, this, std::placeholders::_1, std::placeholders::_2));
        server_.set_open_handler(std::bind(&ControlPC::on_open, this, std::placeholders::_1));
        // Listen on a specific port (8080 in this example)
        server_.listen(8081);

        // Start the WebSocket server
        server_.start_accept();

        // Run the WebSocket server
        server_.run();
    }

private:
    server_t server_;

    // Define a WebSocket message handler
    void on_message(websocketpp::connection_hdl hdl, server_t::message_ptr msg) {
        try {
            std::string message = msg->get_payload();
            std::cout << "Received message: " << message << std::endl;

            std::string response;

            if (commandMap_.count(message) > 0) {
                commandMap_[message](hdl, response);
            } else {
                response = "Error: Unknown command.";
            }

            sendResponse(hdl, response);
        } catch (const std::exception& e) {
            std::cerr << "Error processing message: " << e.what() << std::endl;
        }
    }

    // Define a WebSocket open handler
    void on_open(websocketpp::connection_hdl hdl) {
        sendOptions(hdl); // Send options when the connection is established
    }

    // Function to send a response over WebSocket
    void sendResponse(websocketpp::connection_hdl hdl, const std::string& response) {
        try {
            server_.send(hdl, response, websocketpp::frame::opcode::text);
        } catch (const std::exception& e) {
            std::cerr << "Error sending response: " << e.what() << std::endl;
        }
    }

    // Function to send available options over WebSocket
    void sendOptions(websocketpp::connection_hdl hdl) {
        try {
            std::string options = "Options:\n";
            for (const auto& pair : commandMap_) {
                options += pair.first + "\n";
            }
            server_.send(hdl, options, websocketpp::frame::opcode::text);
        } catch (const std::exception& e) {
            std::cerr << "Error sending options: " << e.what() << std::endl;
        }
    }

    // Function to set the system volume using ALSA
    void setVolume(websocketpp::connection_hdl hdl, std::string& response, int volumePercentage) {
        long min, max;
        snd_mixer_t *handle;
        snd_mixer_elem_t *elem;
        const char *mixer = "Master"; // Adjust for your system (e.g., "Master" or "PCM")

        // Open the mixer
        snd_mixer_open(&handle, 0);

        // Attach the mixer
        snd_mixer_attach(handle, "default");

        // Register the mixer
        snd_mixer_selem_register(handle, NULL, NULL);

        // Load the mixer
        snd_mixer_load(handle);

        // Get the simple element
        elem = snd_mixer_first_elem(handle);

        // Set the volume (percentage of the maximum volume)
        snd_mixer_selem_get_playback_volume_range(elem, &min, &max);
        snd_mixer_selem_set_playback_volume_all(elem, (max * volumePercentage) / 100);

        // Close the mixer
        snd_mixer_close(handle);

        if(volumePercentage == 0){
            response = "volume muted";
        }
        else if(volumePercentage == 100){
            response = "volume unmuted";
        }
        else if(volumePercentage == 35){
            response = "volume increased";
        }
        else{
            response = "volume increased";
        }
    }

    // Function to open the terminal
    void openTerminal(websocketpp::connection_hdl hdl, std::string& response) {
        system("x-terminal-emulator"); // Replace with your preferred terminal emulator command
        response = "Terminal opened.";
    }

    // Function to open home directory
    void openHome(websocketpp::connection_hdl hdl, std::string& response) {
        int result = system("xdg-open ~");
        response = (result == 0) ? "Success: Home directory opened." : "Error: Failed to open the home directory.";
     }
    // Function to open browser
    void openBrowser(websocketpp::connection_hdl hdl, std::string& response) {
        int result = system("xdg-open http://youtube.com");
        response = (result == 0) ? "Success: Browser opened." : "Error: Failed to open the browser.";
    }

    // Function to retrieve battery percentage
    void getBatteryPercentage(websocketpp::connection_hdl hdl, std::string& response) {
#if defined(__linux__)
        std::string batteryPercentage;
        // Linux-specific code to read battery status from /sys/class/power_supply
        std::ifstream batteryFile("/sys/class/power_supply/BAT0/capacity");
        if (batteryFile) {
            batteryFile >> batteryPercentage;
            response = "Battery Percentage: " + batteryPercentage + "%";
        } else {
            response = "Error: Failed to retrieve battery percentage.";
        }
#else
        response = "Error: Battery status not available on this platform.";
#endif
    }

    // Map of commands to corresponding functions
    std::map<std::string, std::function<void(websocketpp::connection_hdl, std::string&)>> commandMap_ = {
        {"terminal", std::bind(&ControlPC::openTerminal, this, std::placeholders::_1, std::placeholders::_2)},
        {"chrome", std::bind(&ControlPC::openBrowser, this, std::placeholders::_1, std::placeholders::_2)},
        {"home", std::bind(&ControlPC::openHome, this, std::placeholders::_1, std::placeholders::_2)},
        {"battery", std::bind(&ControlPC::getBatteryPercentage, this, std::placeholders::_1, std::placeholders::_2)},
        {"volume_up", std::bind(&ControlPC::setVolume, this, std::placeholders::_1, std::placeholders::_2, 35)},
        {"volume_down", std::bind(&ControlPC::setVolume, this, std::placeholders::_1, std::placeholders::_2, -35)},
        {"mute", std::bind(&ControlPC::setVolume, this, std::placeholders::_1, std::placeholders::_2, 0)},
        {"unmute", std::bind(&ControlPC::setVolume, this, std::placeholders::_1, std::placeholders::_2, 100)}
    };
};

int main() {
    ControlPC controlPC;
    return 0;
}