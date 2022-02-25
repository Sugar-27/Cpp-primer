#include "15_30.h"

int main() {
    Basket basket;
    // for (unsigned i = 0; i != 10; ++i)
    //     basket.add_item(Bulk_quote("Bible", 20.6, 20, 0.3));

    // for (unsigned i = 0; i != 10; ++i)
    //     basket.add_item(Bulk_quote("C++Primer", 30.9, 5, 0.4));

    // for (unsigned i = 0; i != 10; ++i)
    //     basket.add_item(Quote("CLRS", 40.1));

    // basket.total_receipt(cout);
    vector<shared_ptr<Quote>> v;
    v.push_back(make_shared<Quote>("book1", 10));
    v.push_back(make_shared<Bulk_quote>("book2", 10, 5, 0.5));
    v.push_back(make_shared<Limit_quote>("book3", 10, 5, 0.5));
    for (int i = 0; i < v.size(); ++i) {
        cout << v[i]->net_price(i + 5) << endl;
    }
    return 0;
}