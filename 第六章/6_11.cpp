#include <iostream>
using namespace std;
void reset(int &n);

int main()
{
    int num = 100;
    int &n = num;
    reset(n);
    cout << num << endl;
}

void reset(int &n)
{
    n = 0;
}