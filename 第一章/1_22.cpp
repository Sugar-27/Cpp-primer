#include <iostream>
#include "Sales_item.h"

int main()
{
    int num = 0;
    Sales_item item, sum;
    if (std::cin >> sum)
    {
        while (std::cin >> item)
            sum += item;
    }
    std::cout << sum << std::endl;
    return 0;
}