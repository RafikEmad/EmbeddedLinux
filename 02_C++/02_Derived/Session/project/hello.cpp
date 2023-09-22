#include<iostream>
#include "hello.hpp"


namespace rafik{
    hello::hello(){}
    hello::~hello(){}
    void fun(int x,int y){std::cout <<"Namespace"<<std::endl;}
    void hello::fun(double x,double y){}
}
