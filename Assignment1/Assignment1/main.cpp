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
    Inventory inv(2);
    
    Item* mac = new Item(1, "Mac n Cheese", 1, 1.01);
    PerishableItem* apple = new PerishableItem(2, "Apple", 1, 1.01, "Febuary 21, 2004");
    NonPerishableItem* stick = new NonPerishableItem(3, "Stick", 1, 1.01, 5);
    
    inv.addItem(mac);
    inv.displayItems();
    inv.addItem(apple);
    inv.addItem(stick);
    inv.displayItems();
    
    inv.removeItem(1);
    inv.displayItems();
    
    return 0;
}
