#include <iostream>

using namespace std;

int main()
{
    string word;
    cin >> word;
    cout << word << endl;
    getline(cin, word);
    cout << word << endl;
    return 0;
}