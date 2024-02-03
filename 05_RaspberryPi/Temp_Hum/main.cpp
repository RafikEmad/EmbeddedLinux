#include "readings.hpp"

int main() {
    std::string file1 = "/sys/bus/iio/devices/iio:device0/in_humidityrelative_input";
    std::string file2 = "/sys/bus/iio/devices/iio:device0/in_temp_input";
    std::string csvFilename = "sensor_data.csv";
    std::string ledPath = "/sys/class/leds/indicator"; 
    ReadingsReader readingsReader(file1, file2, csvFilename, ledPath);
    readingsReader.run();

    return 0;
}
