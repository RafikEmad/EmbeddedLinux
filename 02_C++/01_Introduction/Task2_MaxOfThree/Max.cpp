#include<iostream>

int MaxOfThree(int x, int y,int z)
{
    if(x>y)
    {
        if(x>z)
        {
            return x;
        }
        else
        {
            return z;
        }
    }
    else 
    {
        if(y>z)
        {
            return y;
        }
        else 
            return z;
    }
}

#include <algorithm>

int MaxOfThreeOptimized(int x, int y, int z) {
    return std::max(std::max(x, y), z);
}


int main()
{
    int x,y,z;
    std::cout<<"Enter 3 int numbers:"<<std::endl;
    std::cin>>x>>y>>z;
    std::cout<<MaxOfThree(x,y,z)<<std::endl;
    std::cout<<MaxOfThreeOptimized(x,y,z)<<std::endl;
}