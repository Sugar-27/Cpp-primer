#include <iostream>
#include <vector>

using namespace std;
int fact(int num);
int main()
{
    int num;
    cout << "enter a number:" << endl;
    cin >> num;
    int fact_num = fact(num);
    cout << fact_num << endl;
}

int fact(int num)
{
    int a = 1;
    while (num > 1)
    {
        a *= num--;
    }
    return a;
}