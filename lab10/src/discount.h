#ifndef DISCOUNT_H
#define DISCOUNT_H
#include <vector>
#include "item.h"

using std::vector;

class Discount {
public:
    Discount(int id);
    const int getID() const;
    virtual double total(const vector< Item<Product> > &items) const =0;
private:
    int id;
};

class FixedDiscount : public Discount {
public:
    FixedDiscount(int id, double amount);
    double total(const vector< Item<Product> > &items) const;
private:
    double amount;
};

class PercentageDiscount : public Discount {
public:
    PercentageDiscount(int id, int percentange);
    double total(const vector< Item<Product> > &items) const;
private:
    int percentage;
};


#endif //DISCOUNT_H
