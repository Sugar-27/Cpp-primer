#include <iostream>
#include <vector>

using namespace std;
int count_num();
int main()
{
    for (size_t i = 0; i < 11; i++)
    {
        count_num();
    }
    int a = count_num();
    cout << a << endl;
}

int count_num()
{
    static int num = 0;
    return num++;
}