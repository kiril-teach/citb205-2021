#include "textprinter.h"
#include <iostream>

void TextPrinter::print(std::ostream &out, Invoice invoice) {
    for (auto item : invoice.getItems()) {
        out << item.getQuantity() <<  " | " << item.total() << std::endl;
    }

    out << invoice.subtotal() << std::endl;
    out << invoice.taxes() << std::endl;
    out << invoice.total() << std::endl;
}
