//
//  Item.hpp
//  Assignment1
//
//  Created by Imrahn Faqiri on 2025-01-21.
//

#ifndef Item_hpp
#define Item_hpp

#include <iostream>
using namespace std;

class Item {
private:
    int id;
    string name;
    int quantity;
    double price;
public:
    // Constructor
    Item(int id, const string& name, int quantity, double price)
    : id(id), name(name), quantity(quantity), price(price) {}
    
    // Getters
    int getId() const { return id; }
    const string& getName() const { return name; }
    int getQty() const { return quantity; }
    double getPrice() const { return price; }
    
    // Display method (no need for a seperate cpp file), wouldn't really be used.
    virtual void display() {
        cout << "[" << getId() << "] " << getName() << " | Qty: " << getQty() << "x @$" << getPrice() << endl;
    }
};

#endif /* Item_hpp */
