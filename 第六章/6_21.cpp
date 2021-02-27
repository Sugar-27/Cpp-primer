#include <iostream>

using namespace std;
int test(int a, const int *p);
int main()
{
    int num1 = 1, num2 = 3;
    int *p = &num2;
    cout << test(num1, p) << endl;
}

int test(int a, const int *p)
{
    int max;
    max = (a < *p) ? *p : a;
    return max;
}