#include <iostream>

int add(int &x)
{
    int *res, y;
    int *a, b;
    b = 10;
    a = &b;
    res = &x;
    y = *res;
    for (int xx=0; xx<=y; xx++){
        std::cout << xx << std::endl;
    }
    return *a;
    
}

int main()
{ 
    int x = 5;
    int z;
    z = add(x);
    std::cout<< z << std::endl;
}
