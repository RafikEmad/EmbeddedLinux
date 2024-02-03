#ifndef CSVWRITER_HPP
#define CSVWRITER_HPP

#include <fstream>
#include <iostream>
#include <sstream>
#include <chrono>

class CsvWriter {
public:
    CsvWriter(const std::string& filename);

    void writeHeaders();
    void updateCsv(int temperature, int humidity);

private:
    std::ofstream csvFile;
};

#endif // CSVWRITER_HPP
