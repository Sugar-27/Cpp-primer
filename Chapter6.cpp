#include "Chapter6.h"
#include <iostream>

int fact(int num)
{
    int a = 1;
    while (num > 1)
    {
        a *= num--;
    }
    return a;
}

int abs_(int num)
{
    int abs_num;
    abs_num = (num < 0) ? -num : num;
    return abs_num;
}