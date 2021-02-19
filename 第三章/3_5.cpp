#include <iostream>

using namespace std;
int main()
{
    string str, s;
    while (cin >> s)
    {
        str += s + ' ';
    }
    cout << str << endl;
    return 0;
}