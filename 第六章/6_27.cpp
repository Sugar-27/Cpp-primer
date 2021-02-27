#include <iostream>
#include <vector>

using namespace std;

int sum(std::initializer_list<int> const &il);
int main()
{
    auto nums = {1, 2, 3, 4, 5, 6};
    cout << sum(nums) << endl;
}

int sum(std::initializer_list<int> const &il)
{
    int sum = 0;
    for (auto &num : il)
    {
        sum += num;
    }
    return sum;
}