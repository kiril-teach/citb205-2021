#ifndef INVENTORY_H
#define INVENTORY_H

#include <vector>
#include "item.h"

using std::vector;

class Inventory {
public:
    void add(Product *product, int quantity) 
    {
        for (int i=0; i<items.size(); i++) {
            if (items[i].getProduct().getID() == product->getID()) {
                items[i].add(quantity);
                return;
            }
        }
        Item item(product, quantity);
        items.push_back(item);
    }
    void remove(Product *product, int quantity)
    {
        for (int i=0; i<items.size(); i++) {
            if (items[i].getProduct().getID() == product->getID()) {
                items[i].remove(quantity);
                if (items[i].getQuantity() < 1) {
                    items.erase(items.begin() + i);
                }
                return;
            }
        }
    }
    const vector<Item> & all() const
    {
        return items;
    }
private:
    vector<Item> items;
};

#endif // INVENTORY_H
