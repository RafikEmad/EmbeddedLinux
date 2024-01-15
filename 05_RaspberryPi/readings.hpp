#ifndef READINGS_HPP
#define READINGS_HPP

#include <thread>
#include "csvwriter.hpp"
#include "ledcontroller.hpp"

class ReadingsReader {
public:
    ReadingsReader(const std::string& file1, const std::string& file2, const std::string& csvFilename, const std::string& ledPath);

    bool readNumbers(int& number1, int& number2);
    void processNumbers(int number1, int number2);
    void run();

private:
    std::string file1_;
    std::string file2_;
    CsvWriter csvWriter;
    LedController ledController;
    bool readNumberFromFile(const std::string& filename, int& number);
};

#endif // READINGS_HPP
