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
    for (auto product : catalog.getProducts()) {
        cout << product->getID() << " - " << product->getName() << endl;
    }
}

void addCommand(const Catalog &catalog, Invoice &invoice, int productID, int qty) {
    invoice.add(catalog.get(productID), qty);
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
       }
    }

    return 0;
}