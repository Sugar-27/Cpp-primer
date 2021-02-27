#include <iostream>
#include <vector>

using namespace std;
int main()
{
    string read, tmp;
    while (cin >> read)
        if (read == tmp)
            break;
        else
            tmp = read;

    if (cin.eof())
        cout << "no word was repeated." << endl;
    else
        cout << read << " occurs twice in succession." << endl;

    return 0;
}