#include "Chapter6.h"
#include <iostream>
#include <vector>

using namespace std;
int main()
{
    int absNum, facNum, num;
    cout << "enter a number:" << endl;
    cin >> num;
    facNum = fact(num);
    cout << "The fact of " << num << " is " << facNum;
    absNum = abs_(num);
    cout << "The abs of " << num << " is " << absNum;
    return 0;
}