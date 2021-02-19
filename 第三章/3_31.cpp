#include <iostream>
#include <vector>

using namespace std;
int main()
{
    int nums[10];
    for (int i = 0; i < 10; i++)
    {
        nums[i] = i;
        cout << nums[i] << ' ';
    }
    cout << endl;
    return 0;
}