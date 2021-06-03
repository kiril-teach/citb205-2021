#ifndef CATALOG_H
#define CATALOG_H

#include <vector>
#include "product.h"
#include "inventory.h"

using std::vector;

class Catalog : public Inventory {
public:
    const Product * get(int id) const;
    void load(string path);
};

#endif //CATALOG_H
