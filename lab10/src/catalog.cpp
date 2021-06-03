#include "catalog.h"

#include <iostream>
#include <fstream>
#include <sstream>

using std::ifstream;
using std::cerr;
using std::endl;
using std::stringstream;

const Product * Catalog::get(int id) const {
    for (auto item : all()) {
        if (item.getProduct().getID() == id) {
            return &item.getProduct();
        }
    }
    return NULL;
}

void Catalog::load(string path) {
   ifstream fin(path);
   if (fin.fail()) {
       cerr << "Cannot open file " << path << endl;
   }
   string line;
   string nop;
   while(getline(fin, line)) {
       stringstream ss(line);
       
       int id;
       double price;
       string name;
       int qty;

       ss >> id;
       getline(ss, nop, ',');
       getline(ss, name, ',');
       ss >> price;
       getline(ss, nop, ',');
       ss >> qty;
       if (ss.fail()) {
           cerr << "Cannot parse '" << line << "'" << endl;
           continue;
       }
       add(new Product(id, name, price), qty);
   }
}
