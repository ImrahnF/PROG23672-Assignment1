//
//  Inventory.hpp
//  Assignment1
//
//  Created by Imrahn Faqiri on 2025-01-21.
//

#ifndef Inventory_hpp
#define Inventory_hpp

#include <iostream>
#include "Item.hpp"

using namespace std;

class Inventory {
private:
    vector<Item*> items;
    int capacity;
    int itemCount;
public:
    // Constructor
    Inventory(int);
    void addItem(Item*);
    void removeItem(int);
    void displayItems();
    void saveToFile();
    void loadFromFile();
};

#endif /* Inventory_hpp */
