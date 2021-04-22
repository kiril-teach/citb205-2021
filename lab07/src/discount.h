#ifndef DISCOUNT_H
#define DISCOUNT_H

class Discount {
public:
    virtual double total() =0;
};

class FixedDiscount : public Discount {
public:
    FixedDiscount(double amount);
    double total();
};

class PercentageDiscount : public Discount {
public:
    PercentageDiscount(int percentange);
    double total();
};


#endif //DISCOUNT_H