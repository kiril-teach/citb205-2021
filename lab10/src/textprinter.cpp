#include "textprinter.h"
#include <iostream>
#include <iomanip>

using std::setw;
using std::setfill;
using std::endl;
using std::left;
using std::right;

void TextPrinter::print(std::ostream &out, const Invoice &invoice) {
    out << std::setprecision(2) << std::fixed;   
    printLineSeparator(out);
    for (auto item : invoice.all()) {
        printLineItem(out, item);
        printLineSeparator(out);
    }
    printSummary(out, "Discounts", invoice.totalDiscounts());
    printSummarySeparator(out);
    printSummary(out, "Subtotal", invoice.subtotal());
    printSummarySeparator(out);
    printSummary(out, "Taxes", invoice.taxes());
    printSummarySeparator(out);
    printSummary(out, "TOTAL", invoice.total());
    printSummarySeparator(out);
}

void TextPrinter::printSummary(std::ostream &out, string label, double value) {
    out << setfill(' ');
    out << setw(58+3) << right << label;
    out << '|';
    out << setw(10) << right << value;
    out << '|';
    out << endl;
}
void TextPrinter::printSummarySeparator(std::ostream &out) {
    out << setfill(' ');
    out << setw(58+3) << "";
    out << '+';
    out << setfill('-') << setw(10) << "";
    out << '+';
    out << endl;
}

void TextPrinter::printLineItem(std::ostream &out, const Item<Product> &item) {
    out << setfill(' ');
    out << '|';
    out << setw(8) << right << item.getQuantity();
    out << '|';
    out << setw(40) << left << item.getObj().getName();
    out << '|';
    out << setw(10) << right << item.getObj().getPrice();
    out << '|';
    out << setw(10) << right << item.total();
    out << '|';
    out << endl;
}

void TextPrinter::printLineSeparator(std::ostream &out) {
    out << setfill('-');
    out << '+';
    out << setw(8) << "";
    out << '+';
    out << setw(40) << "";
    out << '+';
    out << setw(10) << "";
    out << '+';
    out << setw(10) << "";
    out << '+';
    out << endl;
}
