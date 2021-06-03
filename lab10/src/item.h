#ifndef LAB1_ITEM_H
#define LAB1_ITEM_H


#include "product.h"

template <class T>
class Item {
public:
    Item(const T *obj, int quantity);
    double total() const;
    int getQuantity() const;
    const T & getObj() const;
    void remove(int qty);
    void add(int qty);
private:
    const T *obj;
    int quantity;
};

template <class T>
Item<T>::Item(const T *obj, int quantity) : obj(obj) {
    this->quantity = quantity;
}

template <class T>
double Item<T>::total() const {
    return obj->getPrice() * quantity;
}

template <class T>
int Item<T>::getQuantity() const {
    return quantity;
}

template <class T>
const T & Item<T>::getObj() const {
    return *obj;
}

template <class T>
void Item<T>::remove(int qty) {
    quantity -= qty;
}

template <class T>
void Item<T>::add(int qty) {
    quantity += qty;
}


#endif //LAB1_ITEM_H
