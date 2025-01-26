//
//  Inventory.cpp
//  Assignment1
//
//  Created by Imrahn Faqiri on 2025-01-21.
//

#include "Inventory.hpp"
#include "PerishableItem.hpp"
#include "NonPerishableItem.hpp"
#include <fstream>
#include <string>
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
    // Source: https://cplusplus.com/forum/beginner/271440/
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

vector<Item*> readFromFile(const string& filename) {
    ifstream inFile(filename);
    if (!inFile) {
        cout << "Error: could not open the file ypou specified:\n" << filename << endl;
        return {};
    }

    vector<Item*> items;

    // The following 10 lines are creating new variables to hold the data before creating a new Item objet.
    // Perishable vs nonperishable item flag
    int perishable;
    // Item attributes
    int id;
    string name;
    int qty;
    double price;
    // Perishable and NonPerishable item attributes
    string exp;
    int warranty;

    string line;
    while (getline(inFile, line)) {
        // Source: https://cplusplus.com/reference/string/string/getline/
        // Get line method is used to read line by line. Each item object we have stored is separated by line.

        /*
        Inventory data is stored in the format:
        Perishability|ID|Name|Qty|Price|Exp Date or Warranty

        -> separatorPosition and prevPosition is used to track the position of each '|' to separate each piece of data.
        using size_t as they are unsigned types which would help with indexing our string postiions
        */
        size_t separatorPosition = 0;
        size_t prevPosition = 0;

        // Get perishability
        separatorPosition = line.find('|', prevPosition);
        if (separatorPosition == string::npos) continue;  // skip invalid line
        perishable = stoi(line.substr(prevPosition, separatorPosition - prevPosition)); 
        prevPosition = separatorPosition + 1;
        /* 
        [stoi] and [stod] is used for 'string to int' and 'string to double'.
            Source: https://cplusplus.com/reference/string/stoi/
            Source: https://cplusplus.com/reference/string/stod/
        [substr] here is used to grab a substring given a string and in our case, using the above variables to extract its position
            Source: https://cplusplus.com/reference/string/string/substr/
        [string::npos] is a constant value that is used to track the invalid srting position which we use to just skip the line
            Source: https://cplusplus.com/reference/string/string/npos/
        */

        // Get ID
        separatorPosition = line.find('|', prevPosition);
        id = stoi(line.substr(prevPosition, separatorPosition - prevPosition));
        prevPosition = separatorPosition + 1;

        // Get name
        separatorPosition = line.find('|', prevPosition);
        name = line.substr(prevPosition, separatorPosition - prevPosition);
        prevPosition = separatorPosition + 1;

        // Get quantity
        separatorPosition = line.find('|', prevPosition);
        qty = stoi(line.substr(prevPosition, separatorPosition - prevPosition));
        prevPosition = separatorPosition + 1;

        // Get price
        separatorPosition = line.find('|', prevPosition);
        price = stod(line.substr(prevPosition, separatorPosition - prevPosition));
        prevPosition = separatorPosition + 1;

        // Grab the item specific attribute and then create a new item based on perishability and push it to our vector.
        if (perishable) {
            exp = line.substr(prevPosition);
            items.push_back(new PerishableItem(id, name, qty, price, exp));
        }
        else {
            warranty = stoi(line.substr(prevPosition));
            items.push_back(new NonPerishableItem(id, name, qty, price, warranty));
        }
    }

    inFile.close();
    cout << "Data successfully read with no errors\n" << endl;
    return items; // return the array of newly loaded items
}

// Function to write objects to a file
void writeToFile(const string& filename, vector<Item*> items) {
    // Similar to ifstream
    ofstream outFile(filename);
    if (!outFile) {
        cout << "Error: could not open the file ypou specified:\n" << filename << endl;
        return;
    }

    // Loop through our items vector and grab each item
    // Source: https://www.geeksforgeeks.org/range-based-loop-c/
    for (const auto& item : items) {
        // Use '|' to separate each piece of data, write in the format:
        // Perishability|ID|Name|Qty|Price|Exp Date or Warranty


        // Firstly, write the perishability of the item (0 or 1). This is the first thing being written.
        int perishable = item->getPerishability();

        // Write common attributes between Perishable and NonPerishable items while separating them
        outFile << perishable << "|"
            << item->getId() << "|"
            << item->getName() << "|"
            << item->getQty() << "|"
            << item->getPrice() << "|";

        // Write the item specific attribute (warranty or exp date_)
        outFile << item->getSpecificAttribute() << endl;
    }

    outFile.close();
    cout << "Data successfully written with no errors\n" << endl;
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

void Inventory::saveToFile(string filePath) {
    // Implement save
    cout << "\n\n==================================" << endl;
    writeToFile(filePath, items);
    cout << "==================================\n\n" << endl;
}

void Inventory::loadFromFile(string filePath) {
    // Implement load
    cout << "\n\n==================================" << endl;
    items = readFromFile(filePath);
    cout << "Loaded from file: " << filePath << endl;
    cout << "==================================\n\n" << endl;
}
