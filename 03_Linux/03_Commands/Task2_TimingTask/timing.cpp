#include <iostream>
#include <unistd.h>
#include <cstdlib> // for system()
#include <fstream> // for file I/O
#include <sstream>
#include <string>
#include <map>

std::map<std::string, int> dayNameToNumber = {
    {"sunday", 0},
    {"monday", 1},
    {"tuesday", 2},
    {"wednesday", 3},
    {"thursday", 4},
    {"friday", 5},
    {"saturday", 6}
};

int main(int argc, char* argv[]) {
    int option;
    int m_value = 0;
    int h_value = 0;
    int d_value_num = 0; // Using an integer to represent the day of the week
    std::string task_command;

    while ((option = getopt(argc, argv, "m:h:d:")) != -1) {
        switch (option) {
            case 'm':
                m_value = atoi(optarg);
                break;
            case 'h':
                h_value = atoi(optarg);
                break;
            case 'd':
                if (isdigit(optarg[0])) {
                     d_value_num = atoi(optarg);
                } else {
                    // Check if the day name is in the map
                    auto it = dayNameToNumber.find(optarg);
                    if (it != dayNameToNumber.end()) {
                        d_value_num = it->second;
                    } else {
                        std::cerr << "Invalid day of the week." << std::endl;
                        return 1;
                    }
                }
                break;
            default:
                std::cerr << "Usage: " << argv[0] << " -m <int> -h <int> -d <string> <task>" << std::endl;
                return 1;
        }
    }

    if (optind < argc) {
        task_command = argv[optind];
    } else {
        std::cerr << "Error: No task command provided." << std::endl;
        return 1;
    }

    std::cout << "m_value: " << m_value << std::endl;
    std::cout << "h_value: " << h_value << std::endl;
    std::cout << "d_value: " << d_value_num << " (as a number)" << std::endl;
    std::cout << "Task Command: " << task_command << std::endl;

    // Generate a cron schedule using numbers for the day of the week
    std::ostringstream cron_schedule;
    cron_schedule << m_value << " " << h_value << " * * " << d_value_num << " " << task_command;

    // Write the cron schedule to a file
    std::ofstream cron_file("my_cron_schedule");
    if (cron_file.is_open()) {
        cron_file << cron_schedule.str() << std::endl;
        cron_file.close();
    } else {
        std::cerr << "Error writing the cron schedule to a file." << std::endl;
        return 1;
    }

    // Use crontab command to schedule the job
    std::string crontab_command = "crontab my_cron_schedule";
    if (system(crontab_command.c_str()) != 0) {
        std::cerr << "Error scheduling the task with crontab." << std::endl;
        return 1;
    }

    return 0;
}
