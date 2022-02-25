#include "15_3.h"

double print_total(Quote& item, size_t n, ostream& os) {
    double price = item.net_price(n);
    os << "ISBN: " << item.isbn() << "\n"
       << "total_price: " << price << endl;
    return price;
}

int main() {
    Quote q("2211222", 5);
    print_total(q, 10, cout);

    return 0;
}