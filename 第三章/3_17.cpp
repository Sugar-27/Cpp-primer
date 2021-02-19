#include <iostream>
#include <vector>

using namespace std;
int main()
{
    string str;
    vector<string> strs;
    while (cin >> str)
    {
        strs.push_back(str);
    }
    for (auto &_ : strs)
    {
        for (auto &c : _)
            c = toupper(c);
        cout << _ << endl;
    }
    return 0;
}