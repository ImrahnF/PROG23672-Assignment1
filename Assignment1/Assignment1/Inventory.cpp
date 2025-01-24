//
//  Inventory.cpp
//  Assignment1
//
//  Created by Imrahn Faqiri on 2025-01-21.
//

#include "Inventory.hpp"
using namespace std;

// Simply initialize the variables to handle capacity
Inventory::Inventory(int Capacity) {
    capacity = Capacity;
    itemCount = 0;
}

// Get the passed item pointer and add to the items vector
void Inventory::addItem(Item* item) {
    if (itemCount < capacity) { // Ensure that item count does not exceed capacity
        items.push_back(item);
        ++itemCount;
        cout << "\n\n\n\n --|| Added item '" << item->getName() << "' with ID of: " << item->getId() << " ||-- \n\n\n\n";

    }
    else {
        cout << "You currently filled " << capacity << "/" << capacity << " slots" << endl;
    }
}

// Handle deleting the pointers from the vector
void Inventory::removeItem(int id) {
    bool found = false; // Just for displaying the failure of the deletion
    
    // Loop through each item in the vector and grab corresponding id. delete if found.
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

// Loop through each item and display its contents. PerishableItem and NonPerishableItem have their own methods.
void Inventory::displayItems() {
    cout << "\n\n==================================" << endl;
    for (Item* i : items) {
        i->display();
    }
    cout << "\nYou have a total of [" << itemCount << "] items." << endl;
    cout << "==================================\n\n" << endl;
}

void Inventory::saveToFile(string fileName) {
    // Implement save
    cout << "\n\n==================================" << endl;
    cout << "Saved to file: " << fileName << endl;
    cout << "==================================\n\n" << endl;
}

void Inventory::loadFromFile(string fileName) {
    // Implement load
    cout << "\n\n==================================" << endl;
    cout << "Loaded from file: " << fileName << endl;
    cout << "==================================\n\n" << endl;
}
