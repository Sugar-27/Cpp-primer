#ifndef BULKQUOTE_H
#define BULKQUOTE_H

#include "15_3.h"

class Bulk_quote : public Quote {
   public:
    Bulk_quote() = default;
    Bulk_quote(string b, double p, size_t q, double disc)
        : Quote(b, p), min_qty(q), discount(disc) {}
    double net_price(size_t n) const override;

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

#endif