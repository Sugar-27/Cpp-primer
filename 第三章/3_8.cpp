#include <iostream>

using namespace std;
int main()
{
    string str1("Hello, world!");
    string str2("Hello, world!");
    //传统while方法
    decltype(str1.size()) num = 0;
    while (num < str1.size())
    {
        if (!isspace(str1[num]))
            str1[num] = 'X';
        num++;
    }
    cout << str1 << endl;
    //传统for循环方法
    for (num = 0; num < str2.size(); num++)
    {
        if (!isspace(str2[num]))
            str2[num] = 'X';
    }
    cout << str2 << endl;
    return 0;
}