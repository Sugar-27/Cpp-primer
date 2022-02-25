#ifndef LIMIT_QUOTE_H
#define LIMIT_QUOTE_H

#include "15_3.h"

class Limit_quote : public Quote {
   public:
    Limit_quote() = default;
    Limit_quote(string bookno, double p, size_t limit, double disc)
        : Quote(bookno, p), limit(limit), discount(disc) {}
    ~Limit_quote() = default;

    double net_price(size_t n) const override;

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

#endif