#ifndef INVENTORY_H
#define INVENTORY_H

#include <vector>
#include "item.h"

using std::vector;

template <class T>
class Inventory {
public:
    void add(const T *obj, int quantity) 
    {
        for (int i=0; i<items.size(); i++) {
            if (items[i].getObj().getID() == obj->getID()) {
                items[i].add(quantity);
                return;
            }
        }
        Item<T> item(obj, quantity);
        items.push_back(item);
    }
    void remove(const T *obj, int quantity)
    {
        for (int i=0; i<items.size(); i++) {
            if (items[i].getObj().getID() == obj->getID()) {
                items[i].remove(quantity);
                if (items[i].getQuantity() < 1) {
                    items.erase(items.begin() + i);
                }
                return;
            }
        }
    }
    const vector< Item<T> > & all() const
    {
        return items;
    }
private:
    vector< Item<T> > items;
};

template <class T>
void move(Inventory<T> &source, Inventory<T> &dest, const T *product, int qty) {
    source.remove(product, qty);
    dest.add(product, qty);
}

#endif // INVENTORY_H
