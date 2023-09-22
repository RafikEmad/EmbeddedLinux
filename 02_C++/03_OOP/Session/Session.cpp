#include<iostream>

class Data {
    public:
        Data() {count++;}
        static int count;
    private:
        static int value;
};
int Data::value=0;
int Data::count=10;
int main(){
    Data d1;
    Data d2;
    Data d3;
    Data d4;
    std::cout<<Data::count<<std::endl;
    //std::cout<<&(Data::count)<<std::endl;
    return 0;
}