#include <iostream>

using namespace std;
int main()
{
    string str("Hello, world!");
    for (auto &c : str)
        if (!isspace(c))
            c = 'X';

    cout << str << endl;
    return 0;
}