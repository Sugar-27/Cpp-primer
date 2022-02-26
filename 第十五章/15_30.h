#include <iostream>
#include <memory>
#include <set>
#include <string>
#include <vector>

using namespace std;

class Quote {
    friend bool operator!=(const Quote& lhs, const Quote& rhs);

   public:
    Quote() = default;
    Quote(const string& bookNo, double p) : bookNo(bookNo), price(p) {}
    // 拷贝构造函数
    Quote(const Quote& q) : bookNo(q.bookNo), price(q.price) {}
    // 移动构造函数
    Quote(Quote&& q) noexcept : bookNo(move(q.bookNo)), price(move(q.price)) {}

    // 拷贝
    Quote& operator=(const Quote& rhs) {
        if (*this != rhs) {
            bookNo = rhs.bookNo;
            price = rhs.price;
        }
        return *this;
    }
    // 移动
    Quote& operator=(Quote&& rhs) noexcept {
        if (*this != rhs) {
            bookNo = move(rhs.bookNo);
            price = move(rhs.price);
        }
        return *this;
    }
    // clone自己
    virtual Quote* clone() const& { return new Quote(*this); }
    virtual Quote* clone() && { return new Quote(move(*this)); }

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
    cout << "bookNo: " << bookNo << " price: " << price << endl;
}
bool inline operator!=(const Quote& lhs, const Quote& rhs) {
    return lhs.bookNo != rhs.bookNo && lhs.price != rhs.price;
}

class Disc_quote : public Quote {
    friend bool operator!=(const Disc_quote& lhs, const Disc_quote& rhs);

   public:
    Disc_quote() = default;
    Disc_quote(const string& b, double p, size_t q, double disc)
        : Quote(b, p), quantity(q), discount(disc) {}
    // 拷贝构造
    Disc_quote(const Disc_quote& dq)
        : Quote(dq), quantity(dq.quantity), discount(dq.discount) {}
    // 移动构造
    Disc_quote(const Disc_quote&& dq) noexcept
        : Quote(move(dq)),
          quantity(move(dq.quantity)),
          discount(move(dq.discount)) {}
    // 拷贝
    Disc_quote& operator=(const Disc_quote& rhs) {
        Quote::operator=(rhs);
        quantity = rhs.quantity;
        discount = rhs.discount;
        return *this;
    }
    // 移动
    Disc_quote& operator=(Disc_quote&& rhs) noexcept {
        if (*this != rhs) {
            Quote::operator=(move(rhs));
            quantity = move(rhs.quantity);
            discount = move(rhs.discount);
        }
        return *this;
    }
    double net_price(size_t n) const override = 0;
    ~Disc_quote() = default;

   protected:
    size_t quantity = 0;
    double discount = 0.0;
};
bool inline operator!=(const Disc_quote& lhs, const Disc_quote& rhs) {
    return Quote(lhs) != Quote(rhs) && lhs.quantity != rhs.quantity &&
           lhs.discount != rhs.discount;
}

class Bulk_quote : public Disc_quote {
   public:
    Bulk_quote() = default;
    // 有用吗？感觉没用
    // using Disc_quote::Disc_quote;
    Bulk_quote(string b, double p, size_t q, double disc)
        : Disc_quote(b, p, q, disc) {}
    // 拷贝构造
    Bulk_quote(const Bulk_quote& bq) : Disc_quote(bq) {}
    // 移动构造
    Bulk_quote(const Bulk_quote&& bq) : Disc_quote(move(bq)) {}
    ~Bulk_quote() = default;
    // 拷贝
    Bulk_quote& operator=(const Bulk_quote& bq) {
        Disc_quote::operator=(bq);
        return *this;
    }
    // 移动
    Bulk_quote& operator=(const Bulk_quote&& bq) {
        Disc_quote::operator=(move(bq));
        return *this;
    }
    double net_price(size_t n) const override;
    Bulk_quote* clone() const& override { return new Bulk_quote(*this); }
    Bulk_quote* clone() && override { return new Bulk_quote(move(*this)); }
    void debug() const override;
};
double Bulk_quote::net_price(size_t n) const {
    if (n > quantity)
        return quantity * (1 - discount) * price + (n - quantity) * price;
    else
        return (1 - discount) * price * n;
}
void Bulk_quote::debug() const {
    cout << "min_qty: " << quantity << " discount: " << this->discount << endl;
}

class Limit_quote : public Disc_quote {
   public:
    Limit_quote() = default;
    Limit_quote(string b, double p, size_t q, double disc)
        : Disc_quote(b, p, q, disc) {}
    double net_price(size_t n) const override;
    void debug() const override;
};
double Limit_quote::net_price(size_t n) const {
    if (n > quantity)
        return n * price;
    else
        return n * price * (1 - discount);
}
void Limit_quote::debug() const {
    cout << "max_qty: " << quantity << " discount: " << this->discount << endl;
}

class Basket {
   public:
    void add_item(const Quote& sale) {
        items.insert(shared_ptr<Quote>(sale.clone()));
    };
    double total_receipt(ostream& os) const;

   private:
    static bool compare(const shared_ptr<Quote>& a,
                        const shared_ptr<Quote>& b) {
        return a->isbn() < b->isbn();
    }
    multiset<shared_ptr<Quote>, decltype(compare)*> items{compare};
};
double print_total(Quote& item, size_t n, ostream& os);
double Basket::total_receipt(ostream& os) const {
    double sum = 0.0;
    for (auto iter = items.cbegin(); iter != items.cend();
         iter = items.upper_bound(*iter)) {
        sum += print_total(**iter, items.count(*iter), os);
    }
    os << "总共花销：" << sum << endl;
    return sum;
}

double print_total(Quote& item, size_t n, ostream& os) {
    double price = item.net_price(n);
    os << "ISBN: " << item.isbn() << "\n"
       << "total_price: " << price << endl;
    return price;
}