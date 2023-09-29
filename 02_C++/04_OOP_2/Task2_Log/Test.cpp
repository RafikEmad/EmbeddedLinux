#include "Log.hpp"

int main() {
    // Set the log level (you can change this as needed)
    LOG::SetLogLevel(LOG::warn);

    // Create a LOG instance with a file name
    LOG log(LOG::info, "log.csv");


log << std::make_pair(LOG::debug, "Debug message");
log << std::make_pair(LOG::info, "Information message");
log << std::make_pair(LOG::warn, "Warning message");
log << std::make_pair(LOG::error, "Error message");

log.Dump();
log.Clear();
    return 0;
}
