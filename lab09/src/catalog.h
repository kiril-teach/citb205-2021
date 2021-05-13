#ifndef CATALOG_H
#define CATALOG_H

#include <vector>
#include "product.h"

using std::vector;

class Catalog {
public:
    Product * get(int id);
    void load(string path);
private:
    vector<Product *> products;
};

#endif //CATALOG_H