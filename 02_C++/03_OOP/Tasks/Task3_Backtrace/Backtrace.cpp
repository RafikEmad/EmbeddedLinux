#include "Backtrace.hpp"

int Backtrace::indent_level_ = 0;
std::vector<std::string> Backtrace::function_stack_;

Backtrace::Backtrace(const std::string& function_name, bool is_entering)
    : function_name_(function_name), is_entering_(is_entering) {
    if (is_entering_) {
        for (int i = 0; i < indent_level_; i++) {
            std::cout << " ";
        }
        std::cout << "Entered function " << function_name_ << std::endl;
        indent_level_ += 2;

        // Push the function name onto the stack
        function_stack_.push_back(function_name_);
    }
}

Backtrace::~Backtrace() {
    if (!is_entering_) {
        indent_level_ -= 2;
        for (int i = 0; i < indent_level_; i++) {
            std::cout << " ";
        }
        std::cout << "Exited function " << function_name_ << std::endl;

        // Pop the function name from the stack
        function_stack_.pop_back();
    }
}

void Backtrace::PrintBacktrace() {
    std::cout << "Backtrace:" << std::endl;
    for (const std::string& function : function_stack_) {
        std::cout << function << " -> ";
    }
    std::cout << "END" << std::endl;
}
