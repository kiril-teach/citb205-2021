#include "discount.h"

FixedDiscount::FixedDiscount(double amount) : amount(amount) {

}

double FixedDiscount::total() {
    return amount;
}

PercentageDiscount::PercentageDiscount(int percentage) {

}

double PercentageDiscount::total() {
    return 3;
}