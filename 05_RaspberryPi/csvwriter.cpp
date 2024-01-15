#include "csvwriter.hpp"

CsvWriter::CsvWriter(const std::string& filename) {
    csvFile.open(filename, std::ios::app); // Open file in append mode
    if (!csvFile.is_open()) {
        std::cerr << "Error opening CSV file: " << filename << std::endl;
    }
}

void CsvWriter::writeHeaders() {
    if (csvFile.is_open()) {
        csvFile << "Time(s),Temperature(°C),Humidity(%)\n";
    }
}

void CsvWriter::updateCsv(int temperature, int humidity) {
    if (csvFile.is_open()) {
        auto currentTime = std::chrono::system_clock::now();
        auto timePoint = std::chrono::system_clock::to_time_t(currentTime);

        struct tm timeInfo;
        localtime_r(&timePoint, &timeInfo);
        
        char timeStr[9]; // HH:MM:SS\0
        strftime(timeStr, sizeof(timeStr), "%H:%M:%S", &timeInfo);

        csvFile << timeStr << "," << temperature / 1000.0 << "," << humidity / 1000.0 << "\n";
        csvFile.flush(); // Ensure data is written to the file immediately
    }
}
