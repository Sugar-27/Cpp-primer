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

#endif