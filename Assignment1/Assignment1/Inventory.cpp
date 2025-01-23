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
        cout << "\n\n\n\n --|| Added item '" << item->getName() << "' with ID of: " << item->getId() << " ||-- \n\n\n\n";
    }
    else {
        cout << "You currently filled " << capacity << "/" << capacity << " slots" << endl;
    }
}

void Inventory::removeItem(int id) {
    bool found = false;
    for (auto i = items.begin(); i != items.end(); i++) {
        if ((*i)->getId() == id) {
            found = true;
            delete* i;
            items.erase(i);
            cout << "\n\n\n\n --|| Deleted item (ID: " << id << ") ||--\n\n\n\n";
            --itemCount;
            break; // To stop iterating
        }
    }

    if (!found) { cout << "\n\n\n\n --||Could not find item of ID: " << id << " ||--\n\n\n\n"; }
}

void Inventory::displayItems() {
    cout << "\n\n==================================" << endl;
    for (Item* i : items) {
        i->display();
        //cout << "[" << i->getId() << "] - " << i->getName() << endl;
    }
    cout << "\nYou have a total of [" << itemCount << "] items." << endl;
    cout << "==================================\n\n" << endl;
}

void Inventory::saveToFile() {
    // Implement save
}

void Inventory::loadFromFile() {
    // Implement load
}
