#include<iostream>

int SumOfDigits(int num)
{
    int sum =0;
    while(num!=0)
    {
        sum=sum+num%10;
        num=num/10;
    }
    return sum;
}

int main()
{
    int x;
    std::cout<<"Enter Number:"<<std::endl;
    std::cin>>x;
    std::cout<<"Sum of digits = "<<SumOfDigits(x)<<std::endl;
}