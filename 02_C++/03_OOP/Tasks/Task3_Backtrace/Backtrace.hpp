#ifndef BACKTRACE_HPP
#define BACKTRACE_HPP

#include <iostream>
#include <string>
#include <vector>

class Backtrace {
public:
    Backtrace(const std::string& function_name, bool is_entering);
    ~Backtrace();

    static void PrintBacktrace(); // Function to print backtrace

private:
    static int indent_level_;
    static std::vector<std::string> function_stack_;
    std::string function_name_;
    bool is_entering_;
};

#define EnterFn Backtrace backtrace_enter(__PRETTY_FUNCTION__, true)
#define ExitFn Backtrace backtrace_exit(__PRETTY_FUNCTION__, false)
#define PRINT_BT Backtrace::PrintBacktrace()

#endif // BACKTRACE_HPP
