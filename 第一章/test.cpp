#include <iostream>
#include "Sales_item.h"

int main()
{
    Sales_item item;
    if (item.isbn().empty())
        std::cout << "1" << std::endl;
    std::cout << item.isbn() << std::endl;
    return 0;
}