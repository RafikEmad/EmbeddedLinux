#include<iostream>

int fun(int x,int y);

int fun(int x,int y) { return x+y;}
int fun(int x) { return x;}
int fun(double x,double y) { return x+y;}

int main()
{
    std::cout<<"Hello World"<<std::endl;
    int result = fun(2,3);
    int result2 = fun(2.5,3.5);
    std::cout<<result<<std::endl;

    return 0;
}