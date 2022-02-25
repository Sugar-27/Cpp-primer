#include "15_11.h"
#include <memory>
#include <vector>

int main() {
    vector<shared_ptr<Quote>> v;
    v.push_back(make_shared<Quote> ("book1", 10));
    v.push_back(make_shared<Bulk_quote> ("book2", 10, 5, 0.5));
    v.push_back(make_shared<Limit_quote> ("book3", 10, 5, 0.5));
    for (int i = 0; i < v.size(); ++i) {
        cout << v[i]->net_price(i + 5) << endl;
    }
    return 0;
}