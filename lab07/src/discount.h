#ifndef DISCOUNT_H
#define DISCOUNT_H

class Discount {
public:
    double total();
};

class FixedDiscount : public Discount {
public:
    FixedDiscount(double amount);
};

class PercentageDiscount : public Discount {
public:
    PercentageDiscount(int percentange);
};


#endif //DISCOUNT_H