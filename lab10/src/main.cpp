#include <iostream>
#include "invoice.h"
#include "textprinter.h"
#include "discount.h"
#include "catalog.h"

using std::cin;
using std::cout;
using std::endl;

void printCommand(const Invoice &invoice) {
    TextPrinter printer;
    printer.print(cout, invoice);
}

void showCommand(const Catalog &catalog, const Inventory<Discount> discounts) {
    cout << "Products: " << endl;
    for (auto item : catalog.all()) {
        cout << item.getObj().getID() << " - " << item.getObj().getName() << "(" << item.getQuantity() <<  ")" << endl;
    }
    cout << "Discounts: " << endl;
    for (auto d : discounts.all()) {
        cout << d.getObj().getID() << " " << d.getQuantity() << endl;
    }
}

void addCommand(Catalog &catalog, Invoice &invoice, int productID, int qty) {
    auto product = catalog.get(productID);
    move(catalog, invoice, product, qty);
}

void removeCommand(Catalog &catalog, Invoice &invoice, int productID, int qty) {
    auto product = catalog.get(productID);
    move(invoice, catalog, product, qty);
}

void addDiscountCommand(Inventory<Discount> &discounts, Invoice &invoice, int discountID) {
    auto discount = discounts.get(discountID);
    invoice.apply(discounts, discount);
}

int main(int argc, char *argv[]) {
    if (argc != 2) {
        cout << "Please provide a single argument - the path to the products catalog data file!" << endl;
        return -1;
    }

    Catalog catalog;
    catalog.load(argv[1]);

    Inventory<Discount> discounts;
    discounts.add(new FixedDiscount(1, 10), 5);
    discounts.add(new PercentageDiscount(2, 5), 2);

    Invoice invoice;

    string cmd;
    while (cin >> cmd) {
       if (cmd == "print") {
           printCommand(invoice);
       } else if(cmd == "show") {
           showCommand(catalog, discounts);
       } else if(cmd == "add") {
           int id, qty;
           cin >> id >> qty;
           addCommand(catalog, invoice, id, qty);
       } else if (cmd == "remove") {
           int id, qty;
           cin >> id >> qty;
           removeCommand(catalog, invoice, id, qty);
       } else if (cmd == "discount") {
           string subCmd;
           cin >> subCmd;
           if (subCmd == "add") {
               int id;
               cin >> id;
               addDiscountCommand(discounts, invoice, id);
            }
       }
    }

    return 0;
}
