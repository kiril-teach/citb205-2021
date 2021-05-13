#ifndef CATALOG_H
#define CATALOG_H

#include "product.h"

class Catalog {
public:
    Product * get(int id);
};

#endif //CATALOG_H