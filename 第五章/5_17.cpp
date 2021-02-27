#include <iostream>
#include <vector>

using namespace std;
bool compare(vector<int> &a, vector<int> &b);
int main()
{
    vector<int> a = {1, 2, 3, 3, 4, 5, 6, 7};
    vector<int> b = {1, 2, 3, 3};
    if (a.size() <= b.size())
    {
        if (compare(a, b))
        {
            cout << "a is b's prefix." << endl;
        }
    }
    else
    {
        if (compare(b, a))
        {
            cout << "b is a's prefix." << endl;
        }
    }
}

bool compare(vector<int> &a, vector<int> &b)
{
    for (int i = 0; i < a.size(); ++i)
    {
        if (a[i] == b[i])
            ;
        else
            return false;
    }
    return true;
}