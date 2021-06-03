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

void showCommand(const Catalog &catalog) {
    for (auto item : catalog.all()) {
        cout << item.getProduct().getID() << " - " << item.getProduct().getName() << "(" << item.getQuantity() <<  ")" << endl;
    }
}

void move(Inventory &source, Inventory &dest, const Product *product, int qty) {
    source.remove(product, qty);
    dest.add(product, qty);
}

void addCommand(Catalog &catalog, Invoice &invoice, int productID, int qty) {
    auto product = catalog.get(productID);
    move(catalog, invoice, product, qty);
}

void removeCommand(Catalog &catalog, Invoice &invoice, int productID, int qty) {
    auto product = catalog.get(productID);
    move(invoice, catalog, product, qty);
}

void discountCommand(Invoice &invoice, string subCmd) {
    if (subCmd == "fixed") {
        double amount;
        cin >> amount;
        invoice.apply(new FixedDiscount(amount));
    } else if (subCmd == "off") {
        int percentage;
        cin >> percentage;
        invoice.apply(new PercentageDiscount(percentage));
    } else if (subCmd == "clear") {
        invoice.clearDiscounts();
    }
}

int main(int argc, char *argv[]) {
    if (argc != 2) {
        cout << "Please provide a single argument - the path to the products catalog data file!" << endl;
        return -1;
    }

    Catalog catalog;
    catalog.load(argv[1]);

    Invoice invoice;

    string cmd;
    while (cin >> cmd) {
       if (cmd == "print") {
           printCommand(invoice);
       } else if(cmd == "show") {
           showCommand(catalog);
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
           discountCommand(invoice, subCmd);
       }
    }

    return 0;
}
