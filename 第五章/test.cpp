
#include <iostream>
#include <vector>
#include <string>
using std::cin;
using std::cout;
using std::endl;
using std::string;
using std::vector;

int main()
{
    for (int i = 0; i < 15; ++i)
    {
        if (i == 10)
        {
            // cout << i << endl;
            continue;
        }
        cout << i << endl;
    }
}