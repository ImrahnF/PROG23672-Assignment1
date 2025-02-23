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
        : id(id), name(name), quantity(quantity), price(price) {
    }

    // Getters
    int getId() const { return id; }
    const string& getName() const { return name; }
    int getQty() const { return quantity; }
    double getPrice() const { return price; }

    // Display method
    virtual void display() = 0;

    // These are used to help to format the derived item to be properly written to a text file
    virtual int getPerishability() = 0;
    virtual string getSpecificAttribute() = 0;
};

#endif /* Item_hpp */
