#ifndef DISQUOTE_H
#define DISQUOTE_H

#include "15_3.h"

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

#endif