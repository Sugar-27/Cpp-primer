#include "15_14.h"

int main() {
    base bobj("test1");
    base* bp1 = &bobj;
    base& br1 = bobj;
    derived dobj("test2");
    base* bp2 = &dobj;
    base& br2 = dobj;
    cout << "bobj.print(cout): " << endl;
    bobj.print(cout);
    cout << "dobj.print(cout): " << endl;
    dobj.print(cout);
    cout << "bp1->name(): " << endl;
    cout << bp1->name() << endl;
    cout << "bp2->name(): " << endl;
    cout << bp2->name() << endl;;
    cout << "br1.print(cout): " << endl;
    br1.print(cout);
    cout << "br2.print(cout): " << endl;
    br2.print(cout);

    return 0;
}