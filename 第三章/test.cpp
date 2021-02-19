#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;
int main()
{
    vector<int> odd_vector{3, 2, 4, 5, 1};
    sort(odd_vector.begin(), odd_vector.end());
    for (auto num : odd_vector)
    {
        cout << num << ' ';
    }
    cout << endl;
    return 0;
}