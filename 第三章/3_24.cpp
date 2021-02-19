#include <iostream>
#include <vector>

using namespace std;
int main()
{
    vector<int> nums;
    int num;
    while (cin >> num)
    {
        nums.push_back(num);
    }
    for (auto it = nums.begin(); it != nums.end() - 1; it++)
    {
        cout << *it + *(it + 1) << endl;
    }
    auto beg = nums.begin(), end = nums.end() - 1;
    while (beg < end)
    {
        cout << *beg + *end << endl;
        beg++;
        end--;
    }
    return 0;
}