#include <iostream>

using namespace std;
int main()
{
    string str("Hello, world!");
    for (char c : str)
        if (!isspace(c))
            c = 'X';

    cout << str << endl;
    return 0;
}