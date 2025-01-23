//
//  main.cpp
//  Assignment1
//
//  Created by Imrahn Faqiri on 2025-01-18.
//

#include <iostream>
#include "Item.hpp"
#include "PerishableItem.hpp"
#include "NonPerishableItem.hpp"
#include "Inventory.hpp"

using namespace std;

void display_options() {
    cout << "Welcome to the Inventory Management System!\nHere are your options:\n\n";
    cout << "-------------------------------------------" << endl;
    cout << "- Add an item [1]\n- Remove an item by ID [2]\n- Display all items [3]\n- Save [4]\n- Load [5]" << endl;
    cout << "- [6] to exit." << endl;
    cout << "-------------------------------------------\n\n";
    cout << "Please enter your choice:" << endl;
}

bool validateDigits(int& choice) {
    cin >> choice;

    // Check if it is a valid number
    if (cin.fail()) {
        cin.clear();
        cin.ignore(256, '\n');
        return false;
    }

    // If it doesn't fail, we have a valid input!
    cin.clear();
    cin.ignore(256, '\n');
    return true;
}

bool validateDouble(double& choice) {
    cin >> choice;

    // Check if it is a valid number
    if (cin.fail()) {
        return false;
    }

    // CHeck if price is smaller or equal to zero
    if (choice <= 0) {
        return false;
    }

    // If it doesn't fail, we have a valid input!
    cin.clear();
    cin.ignore(256, '\n');
    return true;
}

bool validateString(string& choice) {
    cin >> choice;

    if (choice.empty()) {
        return false; // empty string
    }
    cin.clear();
    cin.ignore(256, '\n');
    return true; // non-empty
}

Item* createItem() {
    cout << "\nCreating a new item!\n";
    int perishable = 0; // 0 = NonPerishableItem, 1 = PerishableItem

    // Item attributes
    int id;
    string name;
    int qty;
    double price;

    // Perishable and NonPerishable item attributes
    string exp;
    int warranty;

    // Determine whether it is perishable or not and then create object
    cout << "Enter [1] to add a Perishable item and [0] to add a Non Perishable item:\n";
    while (!validateDigits(perishable)) {
        cout << "Invalid input. Enter 0 or 1." << endl;
    }

    // Grab the id, name, qty, price
    cout << "Enter the item's ID:\n";
    while (!validateDigits(id)) {
        cout << "Please enter a valid number. " << endl;
    }

    cout << "Enter the item's name:\n";
    while (!validateString(name)) {
        cout << "Please enter a non-empty string." << endl;
    }

    cout << "Enter the item's Quantity:\n";
    while (!validateDigits(qty)) {
        cout << "Please enter a valid number. " << endl;
    }

    cout << "Enter the item's Price:\n";
    while (!validateDouble(price)) {
        cout << "Please enter a valid number greater than 0." << endl;
    }

    // Now, create the item based on its perishablitlity
    if (perishable) {
        // Perishable, add experiation date
        cout << "Enter the expiration date of " << name << "':\n";
        while (!validateString(exp)) {
            cout << "Please enter a non-empty date." << endl;
        }

        // Create object
        return new PerishableItem(id, name, qty, price, exp);
    }
    else {
        // Perishable, add warranty period
        cout << "Enter the warranty period (in months) of '" << name << "':\n";
        while (!validateDigits(warranty)) {
            cout << "Please enter a non-empty date." << endl;
        }

        // Create object
        return new NonPerishableItem(id, name, qty, price, warranty);
    }
}

int deleteItem() {
    int id;

    cout << "Please enter the integer ID of the item you would like to remove:" << endl;
    while (!validateDigits(id)) {
        cout << "Invalid input. Please enter a valid number." << endl;
    }

    return id;
}

/*
Item* createItem() {
    int perishable; // 0 = false, 1 = true;

    // First, determine whether it is a perishable or non persihable item.
}
*/
int main() {
    // Create an inventory object (capacity of 5) and choice variable to behin the program
    Inventory inv(5);
    int choice = 0;
    
    do {
        // Begin by displaying options and grabbing input
        display_options();

        // Do a check for valid input
        if (!validateDigits(choice)) {
            cout << "\n\n--||Invalid input. Please try again||--\n\n" << endl;
            continue; // Skip everything and try again.
        }
        
        // Complete each task.
        switch (choice) {
            case 1:
                inv.addItem(createItem());
                break;
            case 2:
                inv.removeItem(deleteItem());
                break;
            case 3:
                inv.displayItems();
                break;
            case 4:
                inv.saveToFile();
                break;
            case 5:
                inv.loadFromFile();
                break;
            case 6:
                cout << "Exiting program.." << endl;
                break;
            default:
                cout << "\n\n--||Invalid choice. Try again.||--\n\n\n";
        }

    } while (choice != 6); // 6 is the "exit code"
    
    return 0;
}
