#include "invoice.h"

double Invoice::subtotal() const {
    double sum = 0;
    for (auto item : all()) {
        sum += item.total();
    }
    sum -= totalDiscounts();
    return sum;
}

double Invoice::taxes() const {
    return 0.1 * subtotal();
}

double Invoice::total() const {
    return subtotal() + taxes();
}

void Invoice::apply(Inventory<Discount> &discounts, const Discount *discount) {
    move(discounts, this->discounts, discount, 1);
}

double Invoice::totalDiscounts() const {
    double sum = 0;
    for (auto discountItems : discounts.all()) {
        sum += discountItems.getObj().total(all());
    }
    return sum;
}

void Invoice::clearDiscounts() {
    discounts.clear();
}
