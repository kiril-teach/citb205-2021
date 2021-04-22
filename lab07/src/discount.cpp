#include "discount.h"

FixedDiscount::FixedDiscount(double amount) {

}
double FixedDiscount::total() {
    return 2;
}

PercentageDiscount::PercentageDiscount(int percentage) {

}

double PercentageDiscount::total() {
    return 3;
}