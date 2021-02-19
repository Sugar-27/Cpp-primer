#include <iostream>
#include <vector>

using namespace std;
int main()
{
    int nums[5] = {0, 1, 2, 3, 4};
    int *ptr = nums;
    for (size_t i = 0; i < 5; i++)
    {
        *(ptr + i) = 0;
    }
    for (auto c : nums)
    {
        cout << c << ' ';
    }
    cout << endl;
    return 0;
}