#include "15_3.h"
#include "15_5.h"

double print_total(Quote& item, size_t n, ostream& os) {
    double price = item.net_price(n);
    os << "ISBN: " << item.isbn() << "\n"
       << "total_price: " << price << endl;
    return price;
}

int main() {
    Quote q("textbook", 5);
	Bulk_quote b("notebook", 2.5, 10, 0.3);
    print_total(q, 10, cout);
    print_total(b, 2, cout);

    return 0;
}