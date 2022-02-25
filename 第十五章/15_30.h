#include <iostream>
#include <memory>
#include <set>
#include <string>
#include <vector>

using namespace std;

class Quote {
   public:
    Quote() = default;
    Quote(string bookNo, double p) : bookNo(bookNo), price(p) {}
    virtual ~Quote() = default;
    string isbn() const;
    virtual double net_price(size_t n) const;

   protected:
    string bookNo;
    double price;
};
string Quote::isbn() const {
    return bookNo;
}
double Quote::net_price(size_t n) const {
    return n * price;
}

class Disc_quote : public Quote {
   public:
    Disc_quote() = default;
    Disc_quote(string b, double p, size_t q, double disc)
        : Quote(b, p), quantity(q), discount(disc) {}
    double net_price(size_t n) const = 0;

   protected:
    size_t quantity = 0;
    double discount = 0.0;
};

class Bulk_quote : public Disc_quote {
   public:
    Bulk_quote() = default;
    Bulk_quote(string b, double p, size_t q, double disc)
        : Disc_quote(b, p, q, disc) {}
    double net_price(size_t n) const override;
};

double Bulk_quote::net_price(size_t n) const {
    if (n > quantity)
        return quantity * (1 - discount) * price + (n - quantity) * price;
    else
        return (1 - discount) * price * n;
}

class Limit_quote : public Disc_quote {
   public:
    Limit_quote() = default;
    Limit_quote(string b, double p, size_t q, double disc)
        : Disc_quote(b, p, q, disc) {}
    double net_price(size_t n) const override;
};

double Limit_quote::net_price(size_t n) const {
    if (n > quantity)
        return n * price;
    else
        return n * price * (1 - discount);
}
class Basket {
   public:
    void add_item(const Quote& sale) {
        items.insert(shared_ptr<Quote>(sale.clone()));
    };
    double total_receipt(ostream& os) const;

   private:
    static bool compare(const Quote& a, const Quote& b) {
        return a.isbn() < b.isbn();
    }
    multiset<shared_ptr<Quote>, decltype(compare)*> items{compare};
};

double print_total(Quote& item, size_t n, ostream& os) {
    double price = item.net_price(n);
    os << "ISBN: " << item.isbn() << "\n"
       << "total_price: " << price << endl;
    return price;
}

double Basket::total_receipt(ostream& os) const {
    double sum = 0.0;
    for (auto iter = items.cbegin(); iter != items.end();
         iter = items.upper_bound(*iter)) {
        sum += print_total(**iter, items.count(*iter), os);
    }
    os << "总共花销：" << sum << endl;
    return sum;
}