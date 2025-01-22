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

int menu_state; // 0 = menu, 1 = add, 2 = remove, 3 = display, 4 = save, 5 = load
int running = true;

void display_intro() {
    cout << "-------------------------------------------" << endl;
    cout << "Welcome to the Inventory Management System!\nHere are your options:" << endl;
    cout << "- Add [1]\n- Remove [2]\n- Display [3]\n- Save [4]\n- Load [5]" << endl;
    cout << "- [6] to exit." << endl;
    cout << "-------------------------------------------" << endl;
}

void main_loop() {
    display_intro();
    
    int choice = 0;
    
    while (choice != 6) {
        cout << "Enter your desired choice:" << endl;
        cin >> choice;
        switch (choice) {
            case 1:
                cout << "You are using the 'Add' feature " << endl;
                break;
            case 6:
                break;
            default:
                cout << "Invalid choice. Please try again." << endl;
                break;
        }
    }
    
    cout << "Thank you for using the Inventory Mangement System!" << endl;
}

int main() {
    
    //main_loop();
    Inventory inv(5);
    
    Item* mac = new Item(1, "Macbook", 1, 1450.95);
    PerishableItem* apple = new PerishableItem(2, "Apple", 12, 0.98, "Febuary 21, 2004");
    NonPerishableItem* stick = new NonPerishableItem(3, "Stick", 3, 4.00, 90);
    
    inv.addItem(mac);
    inv.displayItems();
    inv.addItem(apple);
    inv.addItem(stick);
    inv.displayItems();
    
    inv.removeItem(2);
    inv.displayItems();
    
    return 0;
}
