#include <iostream>
#include <vector>

using namespace std;
int main()
{
    int num;
    vector<int> nums;
    while (cin >> num)
    {
        nums.push_back(num);
    }
    for (auto i : nums)
        cout << i << endl;
    return 0;
}