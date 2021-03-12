#include <iostream>
#include <vector>
#include <string>
using namespace std;
using Iter = vector<int>::const_iterator;
void print(Iter first, Iter last);

int main()
{
    vector<int> nums = {0, 1, 2, 3, 4, 5};
    print(nums.cbegin(), nums.cend());
}

void print(Iter first, Iter last)
{
    if (first == last)
    {
        cout << "over!" << endl;
        return;
    }
    cout << *first << " ";
    print(++first, last);
}