#include "readings.hpp"

ReadingsReader::ReadingsReader(const std::string& file1, const std::string& file2, const std::string& csvFilename, const std::string& ledPath)
    : file1_(file1), file2_(file2), csvWriter(csvFilename), ledController(ledPath) {}

bool ReadingsReader::readNumberFromFile(const std::string& filename, int& number) {
    std::ifstream file(filename);

    if (file.is_open()) {
        std::string line;
        if (getline(file, line)) {
            std::istringstream iss(line);
            if (iss >> number) {
                return true; // Successfully read a number
            } else {
                std::cout << "Invalid content in " << filename << ": " << line << std::endl;
            }
        } else {
            std::cout << "Empty file: " << filename << std::endl;
        }
        file.close();
    } else {
        std::cout << "Unable to open file: " << filename << std::endl;
    }

    return false; // Failed to read a number
}

bool ReadingsReader::readNumbers(int& number1, int& number2) {
    // Attempt to read a number from file1
    while (!readNumberFromFile(file1_, number1)) {
        // Retry until a number is successfully read
        std::this_thread::sleep_for(std::chrono::seconds(1));
    }

    // Attempt to read a number from file2
    while (!readNumberFromFile(file2_, number2)) {
        // Retry until a number is successfully read
        std::this_thread::sleep_for(std::chrono::seconds(1));
    }

    return true;
}

void ReadingsReader::processNumbers(int number1, int number2) {
    // Process the read numbers or perform other actions as needed
    std::cout << "Read from " << file1_ << ": " << number1 / 1000 << "%" << std::endl;
    std::cout << "Read from " << file2_ << ": " << number2 / 1000 << "°C" << std::endl;

    // Update CSV file
    csvWriter.updateCsv(number2, number1);

    // Blink the LED
    ledController.blink(2); // Blink the LED for 2 seconds
}

void ReadingsReader::run() {
    // Write CSV headers
    csvWriter.writeHeaders();
    
    while (true) {
        int number1, number2;

        if (readNumbers(number1, number2)) {
            processNumbers(number1, number2);
        }

        // Sleep for 10 seconds
        std::this_thread::sleep_for(std::chrono::seconds(10));
    }
}
