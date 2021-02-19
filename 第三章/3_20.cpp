#include <iostream>
#include <vector>

using namespace std;
int main()
{
    vector<int> nums;
    int num;
    while (cin >> num)
        nums.push_back(num);
    for (int i = 0; i < nums.size() - 1; i++)
        cout << nums[i] + nums[i + 1] << endl;
    for (int i = 0; i < nums.size() - 1; i++)
        cout << nums[i] + nums[nums.size() - i - 1] << endl;
    return 0;
}