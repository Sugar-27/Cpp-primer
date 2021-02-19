#include <iostream>

using namespace std;
int main()
{
    string str("Hello, world!");
    string str2("Hello, world!");
    string result;
    for (auto &c : str)
        if (ispunct(c))
        {
            c = '\0';
        }
    cout << str.size() << endl;
    //下面的做法更正确
    for (auto x : str2)
    {
        if (!ispunct(x))
        {
            result += x;
        }
    }
    cout << result.size() << endl;
    return 0;
}