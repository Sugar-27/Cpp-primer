#include <iostream>

using namespace std;
void print(int i)
{
    cout << i << endl;
}

void print(const int *beg, const int *end)
{
    while (beg != end)
    {
        cout << *beg++ << endl;
    }
}

void print(const int nums[], size_t size)
{
    for (size_t i = 0; i != size; i++)
    {
        cout << nums[i] << endl;
    }
}

void print(const int (&nums)[2])
{
    for (auto num : nums)
    {
        cout << num << endl;
    }
}

int main()
{
    int i = 0, j[2] = {0, 1};

    print(i);
    print(begin(j), end(j));
    print(j, end(j) - begin(j));
    print(j);

    return 0;
}