#ifndef TEST_H
#define TEST_H
#include <iostream>

using namespace std;

class TestFa {
   public:
    TestFa() = default;
    // TestFa() { cout << "这是默认构造函数" << endl; }
    TestFa(const int& a, const int& b) : a(a), b(b) {
        cout << "这是自定义的构建函数" << endl;
    }
    void print() { cout << a << " " << b << endl; }

   private:
    int a;
    int b;
};

class TestSon : public TestFa {
   public:
    TestSon() { cout << "这是son的默认构造函数" << endl; }
    TestSon(const int& a, const int& b) : TestFa(a, b) {}
};

#endif