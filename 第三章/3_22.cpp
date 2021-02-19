#include <iostream>
#include <vector>

using namespace std;
int main()
{
    vector<string> str;
    str.push_back("hello1, world");
    str.push_back("");
    str.push_back("goodbye world");
    for (auto it = str.begin(); it != str.end() && !it->empty(); it++)
    {
        for (auto &c : *it)
        {
            c = toupper(c);
        }
        cout << *it << endl;
    }
    return 0;
}