#include <iostream>
int main()
{
    //based on characters
    for(char i='A';i<='Z';i++)
    {
        std::cout<<i<<"   "<<(int)i<<std::endl;
    }
    for(char i='a';i<='z';i++)
    {
        std::cout<<i<<"   "<<(int)i<<std::endl;
    }
    //based on int
    std::cout << "ASCII Table:" << std::endl;
    std::cout << "-----------" << std::endl;
    std::cout << "Decimal\tASCII" << std::endl;

    for (int i = 0; i < 128; ++i) {
        std::cout << i << "\t" << static_cast<char>(i) << std::endl;
    }
}
