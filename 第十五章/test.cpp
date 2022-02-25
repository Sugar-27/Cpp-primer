#include "test.h"

// int main() {
//     Test t;
//     Test_pub tpub;
//     Test_pri tpri;
//     Test_pro tpro;

//     // cout << t.item1 << endl;
//     cout << tpub.item3 << endl;
//     // cout << tpub.item2 << endl;
//     print(t);
//     print(tpub);

//     return 0;
// }

int main() {
    Base b;
    b.fcn();
    D1 d1;
    d1.fcn(1);
    d1.Base::fcn();
    D2 d2;
    d2.fcn();
    d2.f2();
}