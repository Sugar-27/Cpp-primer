#include <iostream>
#include <string>

using std::cout;
using std::endl;
using std::string;

bool any_capital(const string &s);
void to_lower(string &s);
int main()
{
    string str = "Hello, world!";
    if (any_capital(str))
    {
        cout << "have capital" << endl;
    }
    else
    {
        cout << "don't have capital" << endl;
    }
    string str2 = "HELLO, worLd!";
    to_lower(str2);
    cout << str2 << endl;
}

bool any_capital(const string &s)
{
    for (auto i : s)
    {
        if (isupper(i))
        {
            return true;
        }
    }
    return false;
}

void to_lower(string &s)
{
    for (auto &i : s)
    {
        if (isupper(i))
        {
            i = tolower(i);
        }
    }
}