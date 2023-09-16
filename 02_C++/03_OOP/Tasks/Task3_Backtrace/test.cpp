#include "Backtrace.hpp"

void func1();
void func2();
void func3();

void func1(){
    EnterFn;
    func2();
    ExitFn;
}
void func2(){
    EnterFn;
    func3();
    ExitFn;
}

void func3(){
    EnterFn;
    PRINT_BT;
    ExitFn;
}

int main() {
    EnterFn;

    func1();

    ExitFn;

    return 0;
}
