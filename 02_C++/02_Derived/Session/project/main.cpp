#include "hello.hpp"
#include <iostream>
#include <string>

//using namespace rafik;
void fun(int x,int y){}

int main(){
    rafik::hello obj;
    //obj.fun(1,2);
    obj.fun(2.5,3.5);
    fun(1,1);
    std::cout<<"hello world"<<std::endl;
    return 0;
}