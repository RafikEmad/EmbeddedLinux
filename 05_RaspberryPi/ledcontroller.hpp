#ifndef LEDCONTROLLER_HPP
#define LEDCONTROLLER_HPP

#include <string>

class LedController {
public:
    LedController(const std::string& ledPath);

    void setTrigger(const std::string& trigger);
    void blink(int durationSeconds);

private:
    std::string ledPath;
};

#endif // LEDCONTROLLER_HPP
