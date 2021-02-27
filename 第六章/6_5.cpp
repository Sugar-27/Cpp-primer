#include <iostream>
#include <vector>

using namespace std;
int abs_(int num);
int main()
{
    int num;
    cout << "enter a number:" << endl;
    cin >> num;
    int fact_num = abs_(num);
    cout << fact_num << endl;
}

int abs_(int num)
{
    int abs_num;
    abs_num = (num < 0) ? -num : num;
    return abs_num;
}