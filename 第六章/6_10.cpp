#include <iostream>

using namespace std;
void change(int *p, int *q);
int main()
{
    int num1, num2;
    cin >> num1 >> num2;
    int *p = &num1, *q = &num2;
    change(p, q);
    cout << num1 << ' ' << num2 << endl;
}

void change(int *p, int *q)
{
    int num;
    num = *p;
    *p = *q;
    *q = num;
}