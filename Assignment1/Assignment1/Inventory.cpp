//
//  Inventory.cpp
//  Assignment1
//
//  Created by Imrahn Faqiri on 2025-01-21.
//

#include "Inventory.hpp"
using namespace std;

Inventory::Inventory(int Capacity) {
    capacity = Capacity;
    itemCount = 0;
}

void Inventory::addItem(Item* item) {
    if (itemCount < capacity) {
        items.push_back(item);
        ++itemCount;
    } else {
        cout << "You currently filled " << capacity << "/" << capacity << " slots" << endl;
    }
}

void Inventory::removeItem(int id) {
    for (auto i = items.begin(); i != items.end(); i++ ) {
        if ((*i)->getId() == id) {
            delete *i;
            items.erase(i);
            cout << "Deleted item (ID: " << id << ")" << endl;
            --itemCount;
            break; // To stop iterating
        }
    }
}

void Inventory::displayItems() {
    cout << "----------------------------------" << endl;
    for (Item* i : items) {
        i->display();
        //cout << "[" << i->getId() << "] - " << i->getName() << endl;
    }
    cout << "\nYou have a total of [" << itemCount << "] items." << endl;
    cout << "----------------------------------" << endl;
}

void Inventory::saveToFile() {
    // Implement save
}

void Inventory::loadFromFile() {
    // Implement load
}
