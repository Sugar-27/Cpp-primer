#include "15_3.h"
#include "15_5.h"
#include "15_7.h"

double print_total(Quote& item, size_t n, ostream& os) {
    double price = item.net_price(n);
    os << "ISBN: " << item.isbn() << "\n"
       << "total_price: " << price << endl;
    return price;
}

int main() {
    Quote q("textbook", 5);
	Bulk_quote b("notebook", 2.5, 10, 0.3);
    Limit_quote x("storybook", 4, 5, 0.5);
    print_total(q, 10, cout);
    print_total(b, 2, cout);
    print_total(x, 4, cout);
    print_total(x, 6, cout);

    return 0;
}