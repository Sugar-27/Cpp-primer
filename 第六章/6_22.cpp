#include <iostream>

using namespace std;
void chang_ptr(int *&ptr1, int *&ptr2);
int main()
{
    int num1 = 2, num2 = 5;
    int *ptr1 = &num1, *ptr2 = &num2;
    cout << *ptr1 << ' ' << *ptr2 << endl;
    chang_ptr(ptr1, ptr2);
    cout << *ptr1 << ' ' << *ptr2 << endl;
}

void chang_ptr(int *&ptr1, int *&ptr2)
{
    int *ptr = ptr2;
    ptr2 = ptr1;
    ptr1 = ptr;
}