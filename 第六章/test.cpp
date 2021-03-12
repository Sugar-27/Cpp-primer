#include <iostream>
#include <vector>
#include <string>
using namespace std;

int factorial(int val);
int main()
{
    cout << factorial(5) << endl;
}
int factorial(int val)
{
    if (val > 1)
    {
        return factorial(val - 1) * val;
    }
    return 1;
}