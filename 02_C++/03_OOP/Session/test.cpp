#include <iostream>

class Data{
    public: 
        static Data *getinstance(){
            if(ptr == nullptr){
                ptr = new Data();
            }
            return ptr;
        }
        void display() {std::cout<<"hello"<<std::endl;}
    private:
        Data(){}
        static Data *ptr;
};
Data *Data::ptr = nullptr;
int main(){
    Data::getinstance()->display();
    return 0;
}