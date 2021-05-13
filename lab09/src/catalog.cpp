#include "catalog.h"

Product * Catalog::get(int id) {
    if (id == 1) {
        return new Product("Super Mob", 12.90);
    } else if (id == 2) {
        return new Product("Tea Cup", 5.30);
    } else if (id == 3) {
        return new Product("Red Wine Glass", 8.60);
    }
    return 0;
}
