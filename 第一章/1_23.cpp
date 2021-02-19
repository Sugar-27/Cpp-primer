#include <iostream>
#include "Sales_item.h"

int main()
{
    Sales_item book;
    Sales_item books[10]; //只统计十本书籍
    int sale_num[10] = {0};
    int a;
    while (std::cin >> book)
    {
        a = 0;
        for (int i = 0; i < 10; i++)
        {
            if (book.isbn() == books[i].isbn())
            {
                books[i] += book;
                sale_num[i] += 1;
                a = 1;
            }
        }
        if (a == 0)
        {
            for (int i = 0; i < 10; i++)
            {
                if (books[i].isbn().empty())
                {
                    books[i] = book;
                    sale_num[i] += 1;
                    break;
                }
            }
        }
    }
    for (int i = 0; i < 10; i++)
    {
        if (!books[i].isbn().empty())
        {
            std::cout << "isbn:" << books[i].isbn() << "'s sales record:" << sale_num[i] << std::endl;
            std::cout << books[i] << std::endl;
        }
    }
    return 0;
}