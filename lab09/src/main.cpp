#include <iostream>
#include "invoice.h"
#include "textprinter.h"
#include "discount.h"
#include "catalog.h"

int main(int argc, char *argv[]) {
    if (argc != 2) {
        std::cout << "Please provide a single argument - the path to the products catalog data file!" << std::endl;
        return -1;
    }

    Catalog catalog;
    catalog.load(argv[1]);

    Invoice invoice;
    Product *superMob = catalog.get(1);
    Product *teaCup = catalog.get(2);
    Product *redWineGlass = catalog.get(3);

    FixedDiscount *fiveOff = new FixedDiscount(5.0);
    PercentageDiscount *tenPercentsOff = new PercentageDiscount(10);

    invoice.add(fiveOff);
    invoice.add(tenPercentsOff);

    invoice.add(superMob, 5);
    invoice.add(teaCup, 12);
    invoice.add(redWineGlass, 8);

    TextPrinter printer;
    printer.print(std::cout, invoice);
    return 0;
}