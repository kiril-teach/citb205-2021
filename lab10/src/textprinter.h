#ifndef LAB1_TEXTPRINTER_H
#define LAB1_TEXTPRINTER_H

#include "invoice.h"

class TextPrinter {
public:
    void print(std::ostream &out, const Invoice &invoice);
private:
    void printLineSeparator(std::ostream &out);
    void printLineItem(std::ostream &out, const Item<Product> &item);
    void printSummary(std::ostream &out, string label, double value);
    void printSummarySeparator(std::ostream &out);
};


#endif //LAB1_TEXTPRINTER_H
