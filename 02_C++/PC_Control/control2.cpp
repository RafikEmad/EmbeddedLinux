#include <iostream>
#include <websocketpp/config/asio_no_tls.hpp>
#include <websocketpp/server.hpp>
#include <cstdlib> 
#include <alsa/asoundlib.h>
#include <cstring>



#if defined(__linux__)
#include <fstream>
#endif


// Define the WebSocket server type based on the configuration
using server_t = websocketpp::server<websocketpp::config::asio>;

// Define the WebSocket server object
server_t server;

void sendResponse(websocketpp::connection_hdl hdl, const std::string& response) {
    try {
        server.send(hdl, response, websocketpp::frame::opcode::text);
    } catch (const std::exception& e) {
        std::cerr << "Error sending response: " << e.what() << std::endl;
    }
}

std::string getBatteryPercentage() {
    std::string batteryPercentage;

#if defined(__linux__)
    // Linux-specific code to read battery status from /sys/class/power_supply
    std::ifstream batteryFile("/sys/class/power_supply/BAT0/capacity");
    if (batteryFile) {
        batteryFile >> batteryPercentage;
    }
#endif
    return batteryPercentage;
}

// Function to set the system volume using ALSA
void setVolume(int volumePercentage) {
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
}

// Function to open the terminal
void openTerminal() 
{
    system("x-terminal-emulator"); // Replace with your preferred terminal emulator command
}

void openBrowser() 
{
    system("xdg-open http://youtube.com"); 
}

// Define a WebSocket message handler
void on_message(websocketpp::connection_hdl hdl, server_t::message_ptr msg) {
    try {
        std::string message = msg->get_payload();
        std::cout << "Received message: " << message << std::endl;

        std::string response;

        // Process the message and execute system command if needed
        if (message == "home" || message == "3") 
        {
            int result = system("xdg-open ~");

            if (result == 0) 
            {
                response = "Success: Home directory opened.";
            }
            else 
            {
                response = "Error: Failed to open the home directory.";
            }
        } 
        else if (message == "battery" || message == "4") 
        {
            // Retrieve battery percentage and send it as a response
            std::string batteryPercentage = getBatteryPercentage();
            if (!batteryPercentage.empty()) 
            {
                response = "Battery Percentage: " + batteryPercentage + "%";
            }
            else 
            {
                response = "Error: Failed to retrieve battery percentage.";
            }
        }
        else if (message == "volume_up" || message == "7") 
        {
            // Increase volume by 10%
            setVolume(35);
            response = "Volume increased.";
        } 
        else if (message == "volume_down" || message == "8") 
        {
            // Decrease volume by 10%
            setVolume(-35);
            response = "Volume decreased.";
        }
        else if (message == "mute" || message == "5") 
        {
            // Mute the volume
            setVolume(0);
            response = "Volume muted.";
        }
        else if (message == "unmute" || message == "6") 
        {
            // Mute the volume
            setVolume(100);
            response = "Volume unmuted.";
        }            
        else if (message == "terminal"|| message == "1")
        {
            openTerminal();
        }
        else if (message == "chrome" || message == "2")
        {
            openBrowser();
        }
        else {
            response = "Error: Unknown command.";
        }
        // For example, you can send a response back:
        // server.send(hdl, "Received: " + message, msg->get_opcode());
        sendResponse(hdl, response);
    } catch (const std::exception& e) {
        std::cerr << "Error processing message: " << e.what() << std::endl;
    }
}

void sendOptions(websocketpp::connection_hdl hdl) {
    try {
        std::string options = "Options:\n1 - terminal\n2 - chrome\n3 - home\n4 - battery\n5 - mute\n6 - unmute\n7 - volume up\n8 - volume down"; // Customize the options as needed
        server.send(hdl, options, websocketpp::frame::opcode::text);
    } catch (const std::exception& e) {
        std::cerr << "Error sending options: " << e.what() << std::endl;
    }
}

void on_open(websocketpp::connection_hdl hdl) {
    sendOptions(hdl); // Send options when the connection is established
}

int main() {
    try {
        // Initialize the WebSocket server
        server.init_asio();
        server.set_message_handler(&on_message);
        server.set_open_handler(&on_open); 
        // Listen on a specific port (8080 in this example)
        server.listen(8080);

        // Start the WebSocket server
        server.start_accept();

        // Run the WebSocket server
        server.run();
    } catch (const std::exception& e) {
        std::cerr << "Error: " << e.what() << std::endl;
    }

    return 0;
}
