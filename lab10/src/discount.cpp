#include "discount.h"

Discount::Discount(int id) : id(id) {

}

const int Discount::getID() const {
    return id;
}

FixedDiscount::FixedDiscount(int id, double amount) : amount(amount), Discount(id) {

}

double FixedDiscount::total(const vector< Item<Product> > &items) const {
    return amount;
}

PercentageDiscount::PercentageDiscount(int id, int percentage) : percentage(percentage), Discount(id) {

}

double PercentageDiscount::total(const vector< Item<Product> > &items) const {
    double sum = 0;
    for (auto item : items) {
        sum += item.total();
    }
    return (percentage/100.0)*sum;
}
