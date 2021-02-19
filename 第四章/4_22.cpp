#include <iostream>
#include <vector>

using namespace std;
int main()
{

    int grade;
    while (cin >> grade)
    {
        string level;
        // version 1
        level = ((grade < 60) ? "fail" : (grade < 75) ? "low pass"
                                     : (grade > 90)   ? "high pass"
                                                      : "pass");
        cout << level << endl;
        //version 2
        if (grade < 60)
            level = "fail";
        else if (grade < 75)
            level = "low pass";
        else if (grade > 90)
            level = "high pass";
        else
            level = "pass";
        cout << level << endl;
    }
    return 0;
}