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
    int nums2[10];
    for (int i = 0; i < 10; i++)
    {
        nums2[i] = nums[i];
        cout << nums2[i] << ' ';
    }
    cout << endl;
    // vector
    vector<int> nums3(10, 0);
    int i = 0;
    for (auto &num : nums3)
    {
        num += i;
        i++;
    }
    for (auto num : nums3)
        cout << num << ' ';
    cout << endl;
    return 0;
}