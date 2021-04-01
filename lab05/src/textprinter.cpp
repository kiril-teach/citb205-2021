#include "textprinter.h"
#include <iostream>

void TextPrinter::print(std::ostream &out, Invoice invoice) {
    out << invoice.subtotal() << std::endl;
    out << invoice.taxes() << std::endl;
}
