#ifndef QUOTE_H
#define QUOTE_H

#include <iostream>
#include <string>

using namespace std;

class Quote {
   public:
    Quote() = default;
    Quote(string bookNo, double p) : bookNo(bookNo), price(p) {}
    virtual ~Quote() = default;
    string isbn() const;
    virtual double net_price(size_t n) const;
    virtual void debug() const;

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
void Quote::debug() const {
    cout << "书单号：" << bookNo << endl;
    cout << "书籍原价: " << price << endl;
}

class Bulk_quote : public Quote {
   public:
    Bulk_quote() = default;
    Bulk_quote(string b, double p, size_t q, double disc)
        : Quote(b, p), min_qty(q), discount(disc) {}
    double net_price(size_t n) const override;
    void debug() const override;

   private:
    size_t min_qty = 0.0;
    double discount = 0.0;
};

double Bulk_quote::net_price(size_t n) const {
    if (n > min_qty)
        return min_qty * (1 - discount) * price + (n - min_qty) * price;
    else
        return (1 - discount) * price * n;
}

void Bulk_quote::debug() const {
    cout << "书单号：" << bookNo << endl;
    cout << "书籍原价: " << price << endl;
    cout << "可以享受优惠的最大购买数量：" << min_qty << endl;
    cout << "折扣：" << discount << endl;
}

class Limit_quote : public Quote {
   public:
    Limit_quote() = default;
    Limit_quote(string bookno, double p, size_t limit, double disc)
        : Quote(bookno, p), limit(limit), discount(disc) {}
    ~Limit_quote() = default;

    double net_price(size_t n) const override;
    void debug() const override;

   private:
    int limit;
    double discount;
};

double Limit_quote::net_price(size_t n) const {
    if (n > limit)
        return price * n;
    else
        return price * (1 - discount) * n;
}

void Limit_quote::debug() const {
    cout << "书单号：" << bookNo << endl;
    cout << "书籍原价: " << price << endl;
    cout << "享受优惠的数量限制（超过则所有书籍均不享受优惠）：" << limit
         << endl;
    cout << "折扣：" << discount << endl;
}

double print_total(Quote& item, size_t n, ostream& os) {
    double price = item.net_price(n);
    os << "ISBN: " << item.isbn() << "\n"
       << "total_price: " << price << endl;
    return price;
}

#endif