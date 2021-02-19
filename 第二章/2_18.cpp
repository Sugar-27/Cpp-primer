#include <iostream>

int main()
{
    int a = 10;
    std::cout << a << std::endl;
    int *ptr = nullptr;
    ptr = &a;
    *ptr = 521;
    std::cout << a << std::endl;
    return 0;
}