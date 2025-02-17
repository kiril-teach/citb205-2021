#ifndef LAB1_INVOICE_H
#define LAB1_INVOICE_H


#include <vector>
#include "product.h"
#include "item.h"
#include "discount.h"
#include "inventory.h"

using std::vector;

class Invoice : public Inventory<Product> {
public:
    void apply(Inventory<Discount> &discounts, const Discount *discount);
    double subtotal() const;
    double taxes() const;
    double total() const;
    double totalDiscounts() const;
    void clearDiscounts();
private:
    Inventory<Discount> discounts;
};




#endif //LAB1_INVOICE_H
