#include <iostream>

using namespace std;
int main()
{
    int cmd;
    string str1, str2;
    cout << "输入数字1/2选择功能，1输出较大字符串，2输出较长字符串,输入3退出" << endl;
    while (cin >> cmd)
    {
        if (cmd == 1)
        {
            getchar();
            getline(cin, str1);
            getline(cin, str2);
            if (str1 == str2)
                cout << "相等" << endl;
            else if (str1 > str2)
                cout << str1 << endl;
            else
                cout << str2 << endl;
        }
        else if (cmd == 2)
        {
            getchar();
            string str1, str2;
            getline(cin, str1);
            getline(cin, str2);
            if (str1.size() == str2.size())
                cout << "相等" << endl;
            else if (str1.size() > str2.size())
                cout << str1 << endl;
            else
                cout << str2 << endl;
        }
        else if (cmd == 3)
        {
            cout << "quit" << endl;
            break;
        }
        else
            cout << "error" << endl;
    }

    return 0;
}