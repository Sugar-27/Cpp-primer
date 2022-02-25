#ifndef TEST_H
#define TEST_H
#include <iostream>

using namespace std;

// class Test;

// void print(Test& test) {
//     cout << test.item1 << endl;
//     // cout << test.item2 << endl;
//     // cout << test.item3 << endl;
//     cout << "test" << endl;
// }

class Test {
   public:
    friend void print(Test& test) {
        cout << test.item1 << endl;
        cout << test.item2 << endl;
        cout << test.item3 << endl;
        cout << "test" << endl;
    }
    int item1 = 1;

   private:
    int item2 = 2;

   protected:
    int item3 = 3;
};

class Test_pub : public Test {
   public:
    using Test::item3;

   private:
    int item4 = 4;
};
class Test_pri : private Test {
   private:
    int item5 = 5;
};
class Test_pro : protected Test {
   private:
    int item6 = 6;
};

class Base {
   public:
    virtual int fcn() {
        cout << "这是Base::fcn()" << endl;
        return 0;
    }
};

class D1 : public Base {
   public:
    int fcn(int);
    virtual void f2();
};

int D1::fcn(int n) {
    cout << "这是D1新设立的fcn()" << endl;
    return 0;
}

void D1::f2() {
    cout << "这是D1::f2()" << endl;
}

class D2 : public D1 {
   public:
    int fcn(int);
    int fcn();
    void f2();
};
int D2::fcn() {
    cout << "这是D2::fcn()" << endl;
    return 0;
}

void D2::f2() {
    cout << "这是D2::f2()" << endl;
}

#endif