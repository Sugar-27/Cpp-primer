#include <iostream>
#include <vector>

using namespace std;
int main()
{
    vector<int> nums{0, 1, 2, 3, 4, 5, 6, 7, 8, 9};
    for (auto &num : nums)
    {
        num % 2 == 0 ? num : num *= 2;
    }
    for (auto num : nums)
        cout << num << ' ';
    cout << endl;
    return 0;
}